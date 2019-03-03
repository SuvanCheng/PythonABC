#include "STC12C5A60S2.H"
#include "Intrins.h"
#include "math.h"
#include "12864bx.h"

#define U8 unsigned char
#define U16 unsigned int
#define U32 unsigned long
#define ulong unsigned long
#define uchar unsigned char
#define uint unsigned int

#define FOSC 12000000L //18432000L
#define BAUD (256 - FOSC / 32 / 9600)

sbit ACC0 = ACC ^ 0;
sbit ACC7 = ACC ^ 7;

sbit qpled = P1 ^ 7; //去皮灯

unsigned char temp;
unsigned char key;
unsigned char keycount;
unsigned char pslen = 5;
unsigned char getps[4]; //,getps1[6]; //按键记录：同时记录，分别分来开锁和设置新密码
bit keyoverflag;
bit errorflag;
unsigned char dispiccnt; //显示画面  0：正常  1：设置
unsigned int nowweight;  //毛重
unsigned int qupi;       //去重
unsigned int netweight;  //净重
unsigned int oriweight;  //初值
unsigned int danjia;     //单价
unsigned long nowmoney;  //当前金额
unsigned long summoney;  //总额

/*Define ADC operation const for ADC_CONTR*/
//#define ADC_POWER 0x80 //ADC power control bit
//#define ADC_FLAG 0x10 //ADC complete flag
//#define ADC_START 0x08 //ADC start control bit
//#define ADC_SPEEDLL 0x00 //540 clocks
//#define ADC_SPEEDL 0x20 //360 clocks
//#define ADC_SPEEDH 0x40 //180 clocks
//#define ADC_SPEEDHH 0x60 //90 clocks

uchar disflag; //0:不工作  1:低频  2:中频  3:高

uint val, val_1, val_2, val_3, val_4, val_5, val_avg; //采样值
uint tmpweight;                                       //当时转换后的重量
uint curval1;                                         //AD采样值
uchar timecnt;                                        //

uchar workmode; //0: 正常称重  1： 设置单价
uchar qpmode;   //0： 不去皮   1：去皮

unsigned char newchar;
void keydetect();
void Send_Hex(unsigned char c); //发送数据，关闭中断
void display_money();
void display_summoney();
void AD_init1() //通道2初始化
{
    P1M0 |= 0x02; //设置IO口仅为输入
    P1M1 |= 0x02;
    P1ASF = 0x02;
    ADC_RES = 0; //清空AD值
    ADC_RESL = 0;
    ADC_CONTR = 0xc1; //FLAG=0，并且选择端口P1.1；
    _nop_();
    _nop_();
    _nop_();
    _nop_();
}
uint AD_sample() //AD采样
{
    ADC_CONTR &= 0xEF; //清Flage(当AD转换完之后会自动置一，需要软件清0)
    ADC_CONTR |= 0x08; //令start =1;
    while (!(ADC_CONTR & 0x10))
        ; //判断AD转换是否完成。Flage位，否则为0
    val = ADC_RES;
    val = val << 2;
    val = val | ADC_RESL; //10位精度
    return (val * 4.883); //mV;	   //供电电压为4.96V时,放大1000倍  500/1024
}
void channel1() //采集通道1函数
{
    AD_sample();
    val_1 = AD_sample();
    AD_sample();
    val_2 = AD_sample();
    AD_sample();
    val_3 = AD_sample();
    AD_sample();
    val_4 = AD_sample();
    AD_sample();
    val_5 = AD_sample();
    val_avg = (val_1 + val_2 + val_3 + val_4 + val_5) / 5;
}
//void channel2() //采集通道2函数
//{ //uchar j;
//  AD_init2();
//}

////////////////////////////////  Uart  9600bps  /////////////////////////////////////
/**************************串口1初始化函数**************************/

void Serial_Init(void) //串口初始化函数
{
    SCON = 0x50;                 //50		//串口:方式1,允许发送和接收
    TMOD = 0x21;                 //21		//定时器1:模式2,8位自动重装模式,用于产生波特率
    PCON = 0x00;                 //波特率倍增设置
    AUXR = 0x40;                 //timer1 work at 1T mode
    TH1 = TL1 = BAUD;            //115200 bps
    TR1 = 1;                     //开启定时器1
    TH0 = (65535 - 25000) / 256; //0x4C;		  	//设置溢出一次为50ms
    TL0 = (65535 - 25000) % 256; //0x4C;
    TR0 = 1;
    ET0 = 1;
    ES = 1; //开启串口中断
    EA = 1; //开启全局中断
}
/***************************发送字符(ASCII)函数*********************/

void Send_ASCII(unsigned char *b)
{
    ES = 0; //关串口中断
    for (b; *b != '\0'; b++)
    {
        SBUF = *b;
        while (TI != 1)
            ;   //等待发送完成
        TI = 0; //清除发送中断标志位
    }
    ES = 1; //开串口中断
}

/************************发送字符(十六进制)函数*********************/

void Send_Hex(unsigned char c) //发送数据，关闭中断
{
    ES = 0; //关串口中断
    SBUF = c;
    while (TI != 1)
        ;   //等待发送完成
    TI = 0; //清除发送中断标志位
    ES = 1; //开串口中断
}

void diswelcome()
{
    unsigned char n;
    for (n = 0; n < 50; n++)
    {
        GUI_POINT(10, n + 10, 1);
        GUI_POINT(118, 60 - n, 1);
    }
    for (n = 0; n < 108; n++)
    {
        GUI_POINT(10 + n, 60, 1);
        GUI_POINT(118 - n, 10, 1);
    }
}

void disnormal()
{
    Disp_HZ(0, 0, "重");
    Disp_HZ(0, 1, "量");
    Disp_Char('g');

    //Disp_HZ(0,2,"克");
    Disp_HZ(0, 4, "单");
    Disp_HZ(0, 5, "价");
    Disp_HZ(0, 6, "元");
    Disp_Char('/');
    Disp_Char('g');

    Set_Cursor(1, 0);
    Disp_Char(nowweight / 1000);
    Disp_Char((nowweight % 1000) / 100 + 0x30);
    Disp_Char((nowweight % 100) / 10 + 0x30);
    Disp_Char('.');
    Disp_Char(nowweight % 10 + 0x30);
    Disp_Char(' ');
    Disp_Char(' ');
    Disp_Char(' ');
    Disp_Char(' ');
    Disp_Char(danjia / 1000 + 0x30);
    Disp_Char((danjia % 1000) / 100 + 0x30);
    Disp_Char((danjia % 100) / 10 + 0x30);
    Disp_Char('.');
    Disp_Char(danjia % 10 + 0x30);

    Disp_HZ(2, 0, "金");
    Disp_HZ(2, 1, "额");
    Disp_HZ(2, 7, "元");
    Disp_HZ(3, 0, "总");
    Disp_HZ(3, 1, "价");
    Disp_HZ(3, 7, "元");
}

void dissetdj() //单价设置界面
{
    Disp_HZ(0, 1, "单");
    Disp_HZ(0, 2, "价");
    Disp_HZ(0, 3, "设");
    Disp_HZ(0, 4, "置");
    Disp_HZ(0, 5, "元");
    Disp_Char('/');
    Disp_Char('g');
    Disp_HZ(1, 0, "原");
    Disp_HZ(1, 1, "价");
    Disp_HZ(1, 2, "：");
    Set_Cursor(1, 3);
    Disp_Char(danjia / 1000 + 0x30);
    Disp_Char((danjia % 1000) / 100 + 0x30);
    Disp_Char((danjia % 100) / 10 + 0x30);
    Disp_Char('.');
    Disp_Char(danjia % 10 + 0x30);
    Disp_HZ(2, 0, "现");
    Disp_HZ(2, 1, "价");
    Disp_HZ(2, 2, "：");
    Set_Cursor(2, 3);
    Disp_Char('*');
}
void main()
{
    nowmoney = 0;
    summoney = 0;
    nowweight = 0;
    qupi = 0;
    qpled = 1;
    netweight = 0;
    oriweight = 0; //
    workmode = 0;  //正常状态
    danjia = 10;   //放大10倍 XXX.X元/g
    getps[0] = 0;
    getps[1] = 0;
    getps[2] = 0;
    getps[3] = 0;
    keycount = 0; //按键次数记录值，设置单价时用
    Serial_Init();
    Send_Hex(0x31);
    delay_ms(10);
    AD_init1();
    Send_Hex(0x32);
    delay_ms(10);
    Display_Init();
    Send_Hex(0x33);
    Clear_GDRAM();
    Send_Hex(0x34);
    //delay_ms(5);
    //Disp_HZ(1,1,"高");
    //Disp_HZ(1,2,"精");
    //Disp_HZ(1,3,"度");
    //Disp_HZ(1,4,"电");
    //Disp_HZ(1,5,"子");
    //Disp_HZ(1,6,"秤");
    //delay_ms(10);
    //diswelcome();
    //delay_ms(10);
    //Disp_String(2,2,"2016.07");
    //delay_ms(500);
    tmpweight = curval1 * 10 / 3; //放大10倍，精确到0.1g
    oriweight = tmpweight;        //初始重量
    delay_ms(1000);
    Display_Init();
    tmpweight = curval1 * 10 / 3; //放大10倍，精确到0.1g
    if (tmpweight > (oriweight + qupi))
    {
        nowweight = tmpweight - oriweight - qupi;
    }
    else
        nowweight = 0;
    disnormal();
    while (1)
    {
        if (disflag == 1)
        {
            tmpweight = curval1 * 10 / 3; //放大10倍，精确到0.1g
            if (tmpweight > (oriweight + qupi))
            {
                nowweight = tmpweight - oriweight - qupi;
            }
            else
            {
                nowweight = 0;
            }
            if (dispiccnt == 0)
            {
                Set_Cursor(1, 0);
                Disp_Char(nowweight / 1000 + 0x30);
                Disp_Char((nowweight % 1000) / 100 + 0x30);
                Disp_Char((nowweight % 100) / 10 + 0x30);
                Disp_Char('.');
                Disp_Char((nowweight % 10) + 0x30);
                Disp_Char(' ');
                Disp_Char(' ');
                Disp_Char(' ');
                Disp_Char(' ');
                Disp_Char(danjia / 1000 + 0x30);
                Disp_Char((danjia % 1000) / 100 + 0x30);
                Disp_Char((danjia % 100) / 10 + 0x30);
                Disp_Char('.');
                Disp_Char(danjia % 10 + 0x30);
                nowmoney = danjia * nowweight; //精确到分，放大100倍
                display_money();
                display_summoney();
            }
            disflag = 0;
        }
        keydetect();
        delay_ms(5);
    }
}
/*******************************定时器0中断处理函数******************************/

void Timer0(void) interrupt 1 //50ms
{
    TR0 = 0; //停止定时器0
    disflag = 1;
    timecnt++;
    if (timecnt >= 20) //200ms读一次电压
    {
        timecnt = 0;
        channel1();        //读一次电压值
        curval1 = val_avg; //mv
        disflag = 1;
    }
    TH0 = (65535 - 50000) / 256;
    TL0 = (65535 - 50000) % 256;
    TR0 = 1; //开启定时器0
}
/*********************************串口1中断处理函数******************************/

void Serial_Int(void) interrupt 4 //wait receive data
{
    ES = 0; //关串口中断，防止中断嵌套
    if (TI) //如果是发送中断，则不做任何处理
    {
        TI = 0;
        ES = 1; //清除发送中断标志位
    }
    else if (RI)
    {
        RI = 0; //清除接收中断标志位
                //getchar = SBUF;  	//将接收到的字符串存到缓存中
    }
}

void keydetect()
{
    unsigned char i, j;
    P2 = 0xff;
    P2_4 = 0; //第一列检测
    temp = P2;
    temp = temp & 0x0f;
    if ((temp != 0x0f) && (dispiccnt == 1)) //1,2,3,4在设置状态下才有用
    {
        for (i = 10; i > 0; i--) //延时，确认按键
            for (j = 248; j > 0; j--)
                ;
        temp = P2;
        temp = temp & 0x0f;
        if (temp != 0x0f)
        {
            temp = P2;
            temp = temp & 0x0f;
            switch (temp)
            {
            case 0x0e:
                key = 4;
                break;
            case 0x0d:
                key = 3;
                break;
            case 0x0b:
                key = 2;
                break;
            case 0x07:
                key = 1;
                break;
            }
            temp = P2;
            if ((key >= 0) && (key < 10)) //有数字按键按下
            {
                if (keycount < 4)
                {
                    getps[keycount] = key;
                    Set_Cursor(2, 3); //单价设置值最初位置
                    for (i = 0; i < keycount + 1; i++)
                    {
                        Disp_Char(getps[i] + 0x30);
                        if (i == 2)
                        {
                            Disp_Char('.');
                        }
                    }
                    if (keycount < 3)
                        Disp_Char('*');
                }
                keycount++; //当前按下密码个数
                if (keycount == 3)
                {
                    keycount = 3;
                }
                else if (keycount > 3)
                {
                    keycount = 4;
                    keyoverflag = 1; //输入密码超过6个
                }
            }
            temp = temp & 0x0f;
            while (temp != 0x0f) //等待按键释放
            {
                temp = P2;
                temp = temp & 0x0f;
            }
            keyoverflag = 0; //
        }
    }
    P2 = 0xff;
    P2_5 = 0;
    temp = P2;
    temp = temp & 0x0f;
    if ((temp != 0x0f) && (dispiccnt == 1)) //5,6,7,8在设置状态下才有用
    {
        for (i = 10; i > 0; i--)
            for (j = 248; j > 0; j--)
                ;
        temp = P2;
        temp = temp & 0x0f;
        if (temp != 0x0f)
        {
            temp = P2;
            temp = temp & 0x0f;
            switch (temp)
            {
            case 0x0e:
                key = 8;
                break;
            case 0x0d:
                key = 7;
                break;
            case 0x0b:
                key = 6;
                break;
            case 0x07:
                key = 5;
                break;
            }
            temp = P2;
            if ((key >= 0) && (key < 10))
            {
                if (keycount < 4)
                {
                    getps[keycount] = key;
                    Set_Cursor(2, 3); //单价设置值最初位置
                    for (i = 0; i < keycount + 1; i++)
                    {
                        Disp_Char(getps[i] + 0x30);
                        if (i == 2)
                        {
                            Disp_Char('.');
                        }
                    }
                    if (keycount < 3)
                        Disp_Char('*');
                }
                keycount++;
                if (keycount == 3)
                {
                    keycount = 3;
                }
                else if (keycount > 3)
                {
                    keycount = 4;
                    keyoverflag = 1; //key overflow
                }
            }
            temp = temp & 0x0f;
            while (temp != 0x0f)
            {
                temp = P2;
                temp = temp & 0x0f;
            }
            keyoverflag = 0; //
        }
    }
    P2 = 0xff;
    P2_6 = 0;
    temp = P2;
    temp = temp & 0x0f;
    if (temp != 0x0f)
    {
        for (i = 10; i > 0; i--)
            for (j = 248; j > 0; j--)
                ;
        temp = P2;
        temp = temp & 0x0f;
        if (temp != 0x0f)
        {
            temp = P2;
            temp = temp & 0x0f;
            switch (temp)
            {
            case 0x0e:
                key = 12;
                break;
            case 0x0d:
                key = 11;
                break;
            case 0x0b:
                key = 0;
                break;
            case 0x07:
                key = 9;
                break;
            }
            temp = P2;
            if ((key >= 0) && (key < 10))
            {
                if (dispiccnt == 1) //0,9在设置状态下才有用
                {
                    if (keycount < 4)
                    {
                        getps[keycount] = key;
                        Set_Cursor(2, 3); //单价设置值最初位置
                        for (i = 0; i < keycount + 1; i++)
                        {
                            Disp_Char(getps[i] + 0x30);
                            if (i == 2)
                            {
                                Disp_Char('.');
                            }
                        }
                        if (keycount < 3)
                            Disp_Char('*');
                    }
                    keycount++;
                    if (keycount == 3)
                    {
                        keycount = 3;
                    }
                    else if (keycount > 3)
                    {
                        keycount = 4;
                        keyoverflag = 1; //key overflow
                    }
                }
            }
            else if (key == 12) //  累加键
            {
                summoney = summoney + nowmoney;
            }
            else if (key == 11) //去皮
            {
                if (workmode == 0) //正常模式，小于100克时去皮
                {
                    if (qpmode == 1) //当前去皮模式
                    {
                        qpmode = 0;
                        qpled = 1; //灭灯
                        qupi = 0;  //去皮重清零
                    }
                    else //不去皮状态
                    {
                        tmpweight = curval1 * 10 / 3; //放大10倍，精确到0.1g
                        if (tmpweight < 1000)         //小于100克
                        {
                            qupi = tmpweight;
                            qpmode = 1;
                            qpled = 0; //点灯
                        }
                    }
                }
            }
            temp = temp & 0x0f;
            while (temp != 0x0f)
            {
                temp = P2;
                temp = temp & 0x0f;
            }
            keyoverflag = 0; //?????????
        }
    }
    P2 = 0xff;
    P2_7 = 0;
    temp = P2;
    temp = temp & 0x0f;
    if (temp != 0x0f)
    {
        for (i = 10; i > 0; i--)
            for (j = 248; j > 0; j--)
                ;
        temp = P2;
        temp = temp & 0x0f;
        if (temp != 0x0f)
        {
            temp = P2;
            temp = temp & 0x0f;
            switch (temp)
            {
            case 0x0e:
                key = 16;
                break;
            case 0x0d:
                key = 15;
                break;
            case 0x0b:
                key = 14;
                break;
            case 0x07:
                key = 13;
                break;
            }
            temp = P2;
            if (key == 15) //enter key
            {
            }
            else if (key == 13) //切换工作模式
            {
                if (dispiccnt == 0)
                {
                    Display_Init();
                    dissetdj();
                    dispiccnt = 1;
                    workmode = 1; //设置状态
                }
                else
                {
                    getps[0] = 0;
                    getps[1] = 0;
                    getps[2] = 0;
                    getps[3] = 0;
                    keycount = 0;
                    Display_Init();
                    disnormal();
                    dispiccnt = 0;
                    workmode = 0; //正常状态
                }
            }
            else if (key == 14) //重新设置单价
            {
                if (dispiccnt == 1) //设置模式下有用，清除已经输入单价
                    getps[0] = 0;
                getps[1] = 0;
                getps[2] = 0;
                getps[3] = 0;
                keycount = 0;
                Set_Cursor(2, 3);
                Disp_Char('*');
                Disp_Char(' ');
                Disp_Char(' ');
                Disp_Char(' '); //清除原来的显示
            }
            else if (key == 16) //当前单确认或设置单价确认
            {
                if (workmode == 0) //正常状态
                {
                    summoney = 0;
                }
                else //单价确认
                {
                    danjia = getps[0] * 1000 + getps[1] * 100 + getps[2] * 10 + getps[3];
                    workmode = 0;
                    dispiccnt = 0;
                    getps[0] = 0;
                    getps[1] = 0;
                    getps[2] = 0;
                    getps[3] = 0;
                    keycount = 0;
                    Display_Init();
                    disnormal();
                }
            }
            temp = temp & 0x0f;
            while (temp != 0x0f)
            {
                temp = P2;
                temp = temp & 0x0f;
            }
            keyoverflag = 0; //?????????
        }
    }
}

void display_money()
{
    Set_Cursor(2, 3);
    Disp_Char(nowmoney / 100000 + 0x30);
    Disp_Char((nowmoney % 100000) / 10000 + 0x30);
    Disp_Char((nowmoney % 10000) / 1000 + 0x30);
    Disp_Char((nowmoney % 1000) / 100 + 0x30);
    Disp_Char('.');
    Disp_Char((nowmoney % 100) / 10 + 0x30);
    Disp_Char((nowmoney % 10) + 0x30);
}

void display_summoney()
{
    Set_Cursor(3, 3);
    if (summoney > 0)
    {
        Disp_Char(summoney / 100000 + 0x30);
        Disp_Char((summoney % 100000) / 10000 + 0x30);
        Disp_Char((summoney % 10000) / 1000 + 0x30);
        Disp_Char((summoney % 1000) / 100 + 0x30);
        Disp_Char('.');
        Disp_Char((summoney % 100) / 10 + 0x30);
        Disp_Char((summoney % 10) + 0x30);
    }
    else
    {
        Disp_Char(' ');
        Disp_Char(' ');
        Disp_Char(' ');
        Disp_Char(0x30);
        Disp_Char('.');
        Disp_Char(0x30);
        Disp_Char(0x30);
    }
}