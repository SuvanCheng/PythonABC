### vi语法高亮

```bash
touch .vimrc
gddit .vimrc
```

```bash
set syntax=on "高亮语法
set fenc=utf-8 "设定默认解码 
set fencs=utf-8,usc-bom,euc-jp,gb18030,gbk,gb2312,cp936 
set nocp "或者 set nocompatible 用于关闭VI的兼容模式 
set number "显示行号 
set ai "或者 set autoindent vim使用自动对齐，也就是把当前行的对齐格式应用到下一行 
set si "或者 set smartindent 依据上面的对齐格式，智能的选择对齐方式
set tabstop=4 "设置tab键为4个空格
set sw=4 "或者 set shiftwidth 设置当行之间交错时使用4个空格
set ruler "设置在编辑过程中,于右下角显示光标位置的状态行 
set incsearch "设置增量搜索,这样的查询比较smart 
set showmatch "高亮显示匹配的括号 
set matchtime=5 "匹配括号高亮时间(单位为 1/10 s) set ignorecase "在搜索的时候忽略大小写 
```



## 06-GNU工具简介

[1.GNU开发环境基础120:11](http://www.maiziedu.com/course/388-4243/)
[2.GNU开发环境基础220:05](http://www.maiziedu.com/course/388-4244/)
[3.GNU开发环境基础320:02](http://www.maiziedu.com/course/388-4245/)
[4. GNU开发环境基础413:00](http://www.maiziedu.com/course/388-4246/)

### [5. GNU开发环境基础_gcc编译119:41](http://www.maiziedu.com/course/388-4247/)

从前：

```bash
0. tar -xvzf *.tar.gz
0. tar -xvjf *.tar.bz2
1. ./configure
2. make
3. make install
```

|      |                                 |                |
| ---- | ------------------------------- | -------------- |
| m4   | 多处理器类库                    |                |
| gmp  | GNU的多精度数字运算类库         | 需要依赖m4     |
| mpfr | 多精度浮点运算的C类库           | 需要依赖gmp    |
| mpc  | 复杂的高精度运算的数学运算C类库 | 依赖gmp , mpfr |
| gcc  | 不用说了吧，呵呵                | 依赖上面所有   |



# Ⅱ  应用开发

## 01-linux之io系统编程

### [1. 课程简介 18:08](http://www.maiziedu.com/course/21-215/)

内核的五大功能：

> 文件管理、进程管理、设备管理、内存管理、网络管理

内核接口函数

```c
#include "unistd.h"
#include "stdio.h"
int main()
{
    write(1,"Hello Linux\n",128);  //内核接口函数：write  <-- printf
    return 0;
}
```



### [2. 文件IO操作 20:14](http://www.maiziedu.com/course/21-218/)

四个基本函数：`open` `read` `write` `close`

#### open

```c
#include <sys/types.h> //这里提供类型pid_t和size_t的定义
#include <sys/stat.h>
#include <fcntl.h>

int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);123456
```

#### 返回值

open函数的返回值如果操作成功，它将返回一个文件描述符，如果操作失败，它将返回-1。

#### 参数含义：

##### 1、pathname:

​	指向想要打开的文件路径名，或者文件名。注意，**这个路径名是绝对路径名。文件名则是在当前路径下的。**

##### 2、flags:

​	表示打开文件所采用的操作，我们需要注意的是：**必须指定以下三个常量的一种，且只允许指定一个**

​	**`O_RDONLY`：只读模式；`O_WRONLY`：只写模式；`O_RDWR`：可读可写**

与必选项 `按位或` 起来作为flags的参数

- O_APPEND 表示追加，写在文件的最末尾。
- O_CREAT 表示如果指定文件不存在，则创建这个文件
- O_EXCL 表示如果要创建的文件已存在，则出错，同时返回 -1，并且修改 errno 的值。
- O_TRUNC 表示截断，如果文件存在，并且以只写、读写方式打开，则将其长度截断为0。
- O_NOCTTY 如果路径名指向终端设备，不要把这个设备用作控制终端。
- O_NONBLOCK 如果路径名指向 FIFO/块文件/字符文件，则把文件的打开和后继 I/O设置为非阻塞模式（nonblocking mode）

以下三个常量同样是选用的，它们用于同步输入输出

- O_DSYNC 等待物理 I/O 结束后再 write。在不影响读取新写入的数据的前提下，不等待文件属性更新。
- O_RSYNC read 等待所有写入同一区域的写操作完成后再进行
- O_SYNC 等待物理 I/O 结束后再 write，包括更新文件属性的 I/O

##### 3、mode:

- **文件权限由open的mode参数和当前进程的umask掩码共同决定。**
- **第三个参数是在第二个参数中有O_CREAT时才作用，如果没有，则第三个参数可以忽略**

```c
/* 完成 touch 功能 */
#include "unistd.h"
#include "stdio.h"
#include <fcntl.h>
int main(int argc,char *argv[])
{
    int fd;
    fd = open(argv[1], O_CREAT | O_RDWR, 0777);
    if(fd < 0)
    {
        printf("creat file %s failure\n",argv[1]);
        return -1;
    }
    printf("creat file %s sucess, fd = %d\n",argv[1],fd);
    close(fd);
    return 0;
}
```



#### open函数与fopen函数区别

| 函数  | 来源                   |    操作成功返回    | 操作失败返回 | 缓冲 | 配合使用 |
| :---- | ---------------------- | :----------------: | :----------: | :--: | :------: |
| open  | Unix下系统调用函数     |     文件描述符     |      -1      |  无  |  write   |
| fopen | ANSIC标准中C语言库函数 | 指向文件结构的指针 |              |  有  |  fwrite  |

