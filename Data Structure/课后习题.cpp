/*!（1）将两个递增的有序链表合并为一个递增的有序链表。要求结果链表仍使用原来两个链表的存储空间, 不另外占用其它的存储空间。表中不允许有重复的数据。
[题目分析]
合并后的新表使用头指针Lc指向，pa和pb分别是链表La和Lb的工作指针,初始化为相应链表的第一个结点，从第一个结点开始进行比较，当两个链表La和Lb均为到达表尾结点时，依次摘取其中较小者重新链接在Lc表的最后。如果两个表中的元素相等，只摘取La表中的元素，删除Lb表中的元素，这样确保合并后表中无重复的元素。当一个表到达表尾结点，为空时，将非空表的剩余元素直接链接在Lc表的最后。
[算法描述]*/
void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc)
{ //合并链表La和Lb，合并后的新表使用头指针Lc指向
    pa = La->next;
    pb = Lb->next;
    //pa和pb分别是链表La和Lb的工作指针,初始化为相应链表的第一个结点
    Lc = pc = La; //用La的头结点作为Lc的头结点
    while (pa && pb)
    {
        if (pa->data < pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        //取较小者La中的元素，将pa链接在pc的后面，pa指针后移
        else if (pa->data > pb->data)
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
        //取较小者Lb中的元素，将pb链接在pc的后面，pb指针后移
        else //相等时取La中的元素，删除Lb中的元素
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            q = pb->next;
            delete pb;
            pb = q;
        }
    }
    pc->next = pa ? pa : pb; //插入剩余段
    delete Lb;               //释放Lb的头结点
}
/*!（2）将两个非递减的有序链表合并为一个非递增的有序链表。要求结果链表仍使用原来两个链表的存储空间, 不另外占用其它的存储空间。表中允许有重复的数据。
[题目分析]
合并后的新表使用头指针Lc指向，pa和pb分别是链表La和Lb的工作指针,初始化为相应链表的第一个结点，从第一个结点开始进行比较，当两个链表La和Lb均为到达表尾结点时，依次摘取其中较小者重新链接在Lc表的表头结点之后，如果两个表中的元素相等，只摘取La表中的元素，保留Lb表中的元素。当一个表到达表尾结点，为空时，将非空表的剩余元素依次摘取，链接在Lc表的表头结点之后。
[算法描述]*/
void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc, )
{ //合并链表La和Lb，合并后的新表使用头指针Lc指向
    pa = La->next;
    pb = Lb->next;
    //pa和pb分别是链表La和Lb的工作指针,初始化为相应链表的第一个结点
    Lc = pc = La; //用La的头结点作为Lc的头结点
    Lc->next = NULL;
    while (pa || pb)
    { //只要存在一个非空表，用q指向待摘取的元素
        if (!pa)
        {
            q = pb;
            pb = pb->next;
        }
        //La表为空，用q指向pb，pb指针后移
        else if (!pb)
        {
            q = pa;
            pa = pa->next;
        }
        //Lb表为空，用q指向pa，pa指针后移
        else if (pa->data <= pb->data)
        {
            q = pa;
            pa = pa->next;
        }
        //取较小者*!（包括相等）La中的元素，用q指向pa，pa指针后移
        else
        {
            q = pb;
            pb = pb->next;
        }
        //取较小者Lb中的元素，用q指向pb，pb指针后移
        q->next = Lc->next;
        Lc->next = q;
        //将q指向的结点插在Lc 表的表头结点之后
    }
    delete Lb; //释放Lb的头结点
}

/*!（3）已知两个链表A和B分别表示两个集合，其元素递增排列。请设计算法求出A与B的交集，并存放于A链表中。
[题目分析]
只有同时出现在两集合中的元素才出现在结果表中,合并后的新表使用头指针Lc指向。pa和pb分别是链表La和Lb的工作指针,初始化为相应链表的第一个结点，从第一个结点开始进行比较，当两个链表La和Lb均为到达表尾结点时，如果两个表中相等的元素时，摘取La表中的元素，删除Lb表中的元素；如果其中一个表中的元素较小时，删除此表中较小的元素，此表的工作指针后移。当链表La和Lb有一个到达表尾结点，为空时，依次删除另一个非空表中的所有元素。
[算法描述]*/
void Mix(LinkList &La, LinkList &Lb, LinkList &Lc)
{
    pa = La->next;
    pb = Lb->next;
    pa和pb分别是链表La和Lb的工作指针, 初始化为相应链表的第一个结点
                                          Lc = pc = La; //用La的头结点作为Lc的头结点
    while (pa && pb)
    {
        if (pa->data == pb->data)
        //交集并入结果表中。
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            u = pb;
            pb = pb->next;
            delete u;
        }
        else if (pa->data < pb->data)
        {
            u = pa;
            pa = pa->next;
            delete u;
        }
        else
        {
            u = pb;
            pb = pb->next;
            delete u;
        }
    }
    while (pa)
    {
        u = pa;
        pa = pa->next;
        delete u;
    }
    // 释放结点空间 while (pb)
    {
        u = pb;
        pb = pb->next;
        delete u;
    }
    //释放结点空间
    pc->next = null;
    //置链表尾标记。 delete Lb; //释放Lb的头结点
}
/*!（4）已知两个链表A和B分别表示两个集合，其元素递增排列。请设计算法求出两个集合A和B 的差集*!（即仅由在A中出现而不在B中出现的元素所构成的集合），并以同样的形式存储，同时返回该集合的元素个数。
[题目分析]
求两个集合A和B的差集是指在A中删除A和B中共有的元素，即删除链表中的相应结点,所以要保存待删除结点的前驱，使用指针pre指向前驱结点。pa和pb分别是链表La和Lb的工作指针,初始化为相应链表的第一个结点，从第一个结点开始进行比较，当两个链表La和Lb均为到达表尾结点时，如果La表中的元素小于Lb表中的元素，pre置为La表的工作指针pa删除Lb表中的元素；如果其中一个表中的元素较小时，删除此表中较小的元素，此表的工作指针后移。当链表La和Lb有一个为空时，依次删除另一个非空表中的所有元素。
[算法描述]*/
void Difference * !（LinkList & La, LinkList &Lb, int *n）
{
    //差集的结果存储于单链表La中， *n是结果集合中元素个数，调用时为0
    pa = La->next;
    pb = Lb->next;
    //pa和pb分别是链表La和Lb的工作指针, 初始化为相应链表的第一个结点
    pre = La;
    //pre为La中pa所指结点的前驱结点的指针 while * !（pa && pb）
    {
        if
            *!（pa->data < q->data）
            {
                pre = pa;
                pa = pa->next;
                *n++;
            }
        // A链表中当前结点指针后移 else if *!（pa->data > q->data）q = q->next;
        //B链表中当前结点指针后移 else
        {
            pre->next = pa->next;
            //处理A，B中元素值相同的结点，应删除
            u = pa;
            pa = pa->next;
            delete u;
        }
        //删除结点
    }
}
/*!（5）设计算法将一个带头结点的单链表A分解为两个具有相同结构的链表B、C，其中B表的结点为A表中值小于零的结点，而C表的结点为A表中值大于零的结点*!（链表A中的元素为非零整数，要求B、C表利用A表的结点）。
[题目分析]
B表的头结点使用原来A表的头结点，为C表新申请一个头结点。从A表的第一个结点开始，依次取其每个结点p，判断结点p的值是否小于0，利用前插法，将小于0的结点插入B表,大于等于0的结点插入C表。
[算法描述]*/
void DisCompose(LinkedList A)
{
    B = A;
    B->next = NULL;
    //B表初始化
    C = new LNode;
    //为C申请结点空间
    C->next = NULL;
    //C初始化为空表
    p = A->next;
    //p为工作指针 while (p != NULL)
    {
        r = p->next;
        //暂存p的后继 if (p->data < 0)
        {
            p->next = B->next;
            B->next = p;
        }
        //将小于0的结点链入B表, 前插法 else
        {
            p->next = C->next;
            C->next = p;
        }
        //将大于等于0的结点链入C表, 前插法
        p = r;
        //p指向新的待处理结点。
    }
}

/*!（6）设计一个算法，通过一趟遍历在单链表中确定值最大的结点。
[题目分析]
假定第一个结点中数据具有最大值，依次与下一个元素比较，若其小于下一个元素，则设其下一个元素为最大值，反复进行比较，直到遍历完该链表。
[算法描述]*/
ElemType Max(LinkList L)
{
    if (L->next == NULL)
        return NULL;
    pmax = L->next; //假定第一个结点中数据具有最大值
    p = L->next->next;
    while (p != NULL)
    { //如果下一个结点存在
        if (p->data > pmax->data)
            pmax = p; //如果p的值大于pmax的值，则重新赋值
        p = p->next;  //遍历链表
    }
    return pmax->data;
    /*!（7）设计一个算法，通过遍历一趟，将链表中所有结点的链接方向逆转，仍利用原表的存储空间。
[题目分析]
从首元结点开始，逐个地把链表L的当前结点p插入新的链表头部。
[算法描述]*/
    void inverse(LinkList & L)
    { // 逆置带头结点的单链表 L
        p = L->next;
        L->next = NULL;
        while (p)
        {
            q = p->next; // q指向*p的后继
            p->next = L->next;
            L->next = p; // *p插入在头结点之后
            p = q;
        }
    }
    /*!（8）设计一个算法，删除递增有序链表中值大于mink且小于maxk的所有元素*!（mink和maxk是给定的两个参数，其值可以和表中的元素相同，也可以不同 ）。
[题目分析]
分别查找第一个值>mink的结点和第一个值 ≥maxk的结点，再修改指针，删除值大于mink且小于maxk的所有元素。
[算法描述]*/
    void delete (LinkList & L, int mink, int maxk)
    {
        p = L->next; //首元结点
        while (p && p->data <= mink)
        {
            pre = p;
            p = p->next;
        } //查找第一个值>mink的结点
        if (p)
        {
            while (p && p->data < maxk)
                p = p->next;
            // 查找第一个值 ≥maxk的结点
            q = pre->next;
            pre->next = p; // 修改指针
            while (q != p)
            {
                s = q->next;
                delete q;
                q = s;
            } // 释放结点空间
        }     //if
    }
/*!（9）已知p指向双向循环链表中的一个结点，其结点结构为data、prior、next三个域，写出算法change(p),交换p所指向的结点和它的前缀结点的顺序。
[题目分析]
知道双向循环链表中的一个结点，与前驱交换涉及到四个结点*!（p结点，前驱结点，前驱的前驱结点，后继结点）六条链。
[算法描述]*/
    void Exchange * !（LinkedList p）
    //p是双向循环链表中的一个结点，本算法将p所指结点与其前驱结点交换。
    {
        q = p->llink；
                q->llink->rlink = p；                                                     //p的前驱的前驱之后继为p
                                      p->llink = q->llink；                               //p的前驱指向其前驱的前驱。 q->rlink = p->rlink；   //p的前驱的后继为p的后继。 q->llink = p；          //p与其前驱交换
                                                     p->rlink->llink = q；                //p的后继的前驱指向原p的前驱
                                                                           p->rlink = q； //p的后继指向其原来的前驱
    }
    //算法exchange结束。
/*!（10）已知长度为n的线性表A采用顺序存储结构，请写一时间复杂度为O(n)、空间复杂度为O(1)的算法，该算法删除线性表中所有值为item的数据元素。
[题目分析] 
在顺序存储的线性表上删除元素，通常要涉及到一系列元素的移动*!（删第i个元素，第i+1至第n个元素要依次前移）。本题要求删除线性表中所有值为item的数据元素，并未要求元素间的相对位置不变。因此可以考虑设头尾两个指针*!（i=1，j=n），从两端向中间移动，凡遇到值item的数据元素时，直接将右端元素左移至值为item的数据元素位置。
[算法描述]*/
    void Delete（ElemType A[] ，int n）
    //A是有n个元素的一维数组，本算法删除A中所有值为item的元素。
    {
        i = 1；j = n； //设置数组低、高端指针（下标）
        while（i < j）
        {
            while（i < j &&A[i] != item）i++ ；     //若值不为item，左移指针。
                if（i < j）while（i < j &&A[j] ==
                    item）j-- ；                    //若右端元素为item，指针左移
                if（i < j）A[i++] = A[j--] ；
        }
    }