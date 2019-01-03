# PythonABC

多谢 @[雪峰](https://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/001431676242561226b32a9ec624505bb8f723d0027b3e7000)

## 第一天

2019/1/1

### 基本认识1

#### print和input

```python
>>> print('The quick brown fox', 'jumps over', 'the lazy dog')
The quick brown fox jumps over the lazy dog
>>> print('100 + 200 =', 100 + 200)
100 + 200 = 300
```

```
>>> name = input()
Michael
>>> name
'Michael'
```

#### 数据类型和变量

1.23x109就是`1.23e9`
0.00012可以写成`1.2e-4`

`\n`表示换行
`\t`表示制表符
`\\`表示的字符就是`\`
`...`是提示符，不是代码的一部分

Python 3版本中，字符串是以Unicode编码，字符串支持多语言；
汉字`中`已经超出了ASCII编码的范围，用Unicode编码是十进制的`20013`

```python
>>> print(ord('A'))
65
>>> print(chr(66))
B
>>> print(chr(20013))
中
>>> print(ord('中'))
20013
>>> print('\u4e2d\u6587')
中文
```

#### 字符串和编码

```python
x = b'ABC' # 带`b`前缀的单引号或双引号表示bytes
x = 'ABC' # 单引号或双引号表示str
```

##### `.encode()`

```python
>>> print('中文'.encode('utf-8')) # `str`变为`bytes`
b'\xe4\xb8\xad\xe6\x96\x87'
>>> print('ABC'.encode('ascii'))
b'ABC'
>>> print('中文'.encode('ascii'))
ASCII字符无法表示中文
```

##### `.decode()`

```python
>>> print(b'\xe4\xb8\xad\xe6\x96\x87'.decode('utf-8')) # `bytes`变为`str`
中文
>>> print(b'\xe4\xb8\xad\xe6\x96'.decode('utf-8', errors='ignore'))
中
```

##### `len()`

```
>>> print(len('中文'))
2
>>> print(len('中文'.encode('utf-8')))
6
```

##### `.capitalize()`

```python
>>>s = 'a, B'
>>> s.capitalize()
'A, b'
 
>>> s = ' a, B'    # a 前面有空格
>>> s.capitalize()
' a, b'
 
>>> s = 'a, BCD'
>>> s.capitalize()
'A, bcd'
```

#### %? 占位符

`%s`表示用字符串；`%d`表示用整数；`%f`表示用浮点数；`%x`表示用十六进制数；

```python
>>> print('Hi, %s, you have $%d.' % ('Michael', 1000000))
Hi, Michael, you have $1000000.
```

如果只有一个`%?`，括号可以省略。

```python
>>> print('%5d-%03d' % (3, 1))
    3-001
>>> print('%.4f' % 3.1415926)
3.1416
```

#### list和tuple

##### list 有序集合

```python
>>> classmates = ['Michael', 'Bob', 'Tracy'] #可以随时添加和删除其中的元素
>>> classmates
['Michael', 'Bob', 'Tracy']
```

`len()`

```python
>>> len(classmates) #函数可以获得list元素的个数
3
```

```
>>> classmates[0]
'Michael'
>>> classmates[1]
'Bob'
>>> classmates[2]
'Tracy'
```

```
>>> classmates[-1]
'Tracy'
>>> classmates[-2]
'Bob'
>>> classmates[-3]
'Michael'
```

##### `.append()`

```python
>>> classmates.append('Adam') # 追加
>>> classmates
['Michael', 'Bob', 'Tracy', 'Adam']
```

##### `.insert()`

```python
>>> classmates.insert(1, 'Jack') # 插入
>>> classmates
['Michael', 'Jack', 'Bob', 'Tracy', 'Adam']
```

##### `pop()`

```python
>>> classmates.pop() # 删除list末尾的元素
'Adam'
>>> classmates
['Michael', 'Jack', 'Bob', 'Tracy']
>>> classmates.pop(1) # 删除索引位置的元素
'Jack'
>>> classmates
['Michael', 'Bob', 'Tracy']
```

```python
>>> classmates[1] = 'Sarah' # 替换某个元素，直接赋值给对应的索引位置
>>> classmates
['Michael', 'Sarah', 'Tracy']
```

```python
>>> L = ['Apple', 123, True] # list里面的元素的数据类型可以不同
```

```python
>>> s = ['python', 'java', ['asp', 'php'], 'scheme'] # list元素也可以是另一个list
>>> len(s)
4
```

要拿到`'php'`可以写`p[1]`或者`s[2][1]`，因此`s`可以看成是一个二维数组，类似的还有三维、四维……数组

```python
>>> L = [] # 空的list的长度为0
>>> len(L)
0
```

##### tuple 元组

```python
>>> classmates = ('Michael', 'Bob', 'Tracy') #一旦初始化就不能修改
('Michael', 'Bob', 'Tracy')
>>> t = () # 空的tuple
()
>>> t = (1,) # 只有1个元素的tuple,定义时必须加一个逗号`,`，来消除歧义t = (1)等于括号运算
(1,)
```

同list可用`append()`，`insert()`，`classmates[0]`，`classmates[-1]`，但不能赋值成另外的元素。

“可变的”tuple：

```python
>>> t = ('a', 'b', ['A', 'B'])
>>> t[2][0] = 'X'
>>> t[2][1] = 'Y'
>>> t
('a', 'b', ['X', 'Y'])
```

tuple所谓的“不变”是说，tuple的每个元素，指向永远不变。即指向`'a'`，就不能改成指向`'b'`，指向一个list，就不能改成指向其他对象，但指向的这个list本身是可变的！

```python
L = [
    ['Apple', 'Google', 'Microsoft'],
    ['Java', 'Python', 'Ruby', 'PHP'],
    ['Adam', 'Bart', 'Lisa']
]
>>> print(L[0][0])
Apple
>>> print(L[1][1])
Python
>>> print(L[2][2])
Lisa
```

#### 条件判断

##### if

```python
age = 20
if age >= 18: # 缩进规则：如果if判断是True，就把缩进的语句执行了
    print('your age is', age)
    print('adult')
```

```python
age = 3
if age >= 18: # 缩进规则：如果if判断是False，就把else缩进的语句执行了
    print('your age is', age)
    print('adult')
else:
    print('your age is', age)
    print('teenager')
```

```python
age = 3
if age >= 18:
    print('adult')
elif age >= 6: # 自上而下判断，一旦成立，即放弃接下来的判断
    print('teenager')
else:
    print('kid')
```

```python
if x: # 只要`x`是非零数值、非空字符串、非空list等，就判断为`True`，否则为`False`
    print('True')
```

##### input

```python
h = input('height: ')
h = float(h) # input()返回的是str，必须先把str转换成浮点数
w = input('weight:')
w = float(w)
s = (w/h)/h

if s < 18.5:
    print('slim')
elif s < 25:
    print('handsome')
elif s < 28:
    print('fat')
else:
    print('incorrigible')
```

#### 循环

##### for...in

```python
names = ['Michael', 'Bob', 'Tracy']
for n in names: # 执行这段代码，会依次打印names的每一个元素
    print(n)
```

##### `range()`生成整数序列

```
>>> list(range(5)) # range函数生成一个整数序列，通过list()转换为list
[0, 1, 2, 3, 4]
```

```python
sum = 0
for x in range(101): # 生成0-100的整数序列
    sum = sum + x
print(sum) # 5050
```

##### while

```python
sum = 0
n = 100
while n > 0:
    sum = sum + n
    n = n - 1
print(sum) # 5050
```

```python
L = ['Bart', 'Lisa', 'Adam'] # 练习
for n in L:
    print('Hello,',n)
```

##### `break` 中断

```python
n = 1
while n <= 100:
    if n > 10: # 当n = 11时，条件满足，执行break语句
        break # 循环过程中直接退出循环
    print(n)
    n = n + 1
print('END')
```

##### `continue` 跳过

```python
n = 0
while n < 10:
    n = n + 1
    if n % 2 == 0: # 如果n是偶数，执行continue语句
        continue # 提前结束本轮循环，并开始下一轮循环
    print(n)
```

#### dict和set

##### dict 字典

dict全称dictionary，在其他语言中也称为map，使用键-值（key-value）存储，具有极快的查找速度。

```
>>> d = {'Michael': 95, 'Bob': 75, 'Tracy': 85}
>>> d['Michael']
95
```

```python
>>> d['Adam'] = 67 # 通过key放入dict
>>> d['Adam']
67
```

```python
>>> d['Jack'] = 90 # 一个key只能对应一个value
>>> d['Jack']
90
>>> d['Jack'] = 88 # 对一个key多次放入value，后者的值会覆盖前者
>>> d['Jack']
88
```

```python
>>> 'Thomas' in d # 通过in判断key是否存在
False
```

##### `.get()`

```python
>>> d.get('Thomas') # 如果key不存在，可以返回None
>>> d.get('Thomas', -1) # 或者返回自己指定的value，比如返回-1
-1
```

##### `.pop(key)`

```python
>>> d.pop('Bob') # 删除一个key，对应的value也会从dict中删除
75
>>> d
{'Michael': 95, 'Tracy': 85} # 务必注意，dict内部存放的顺序和key放入的顺序是没有关系的
```

dict的key必须是**不可变对象**。字符串、整数等都是不可变的，因此，可以放心地作为key。而：这个通过key计算位置的算法称为哈希算法（Hash）。

```python
>>> key = [1, 2, 3]
>>> d[key] = 'a list' # list是可变的，就不能作为key
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: unhashable type: 'list'
```

##### set 集合

set和dict类似，也是一组key的集合，但不存储value。

```python
>>> s = set([2, 2, 1, 2, 3, 3, 3]) # 要创建一个set，需要提供一个list作为输入集合
>>> s
{1, 2, 3} # 由于key不能重复，所以，在set中，没有重复的key
```

##### `.add(key)`

```python
>>> s.add(4) # 添加元素，可以重复添加，但不会有效果：
>>> s
{1, 2, 3, 4}
>>> s.add(4)
>>> s
{1, 2, 3, 4}
```

##### `.remove(key)`

```
>>> s.remove(4) # 删除元素
>>> s
{1, 2, 3}
```

```python
>>> s1 = set([1, 2, 3]) # 两个set可以做数学意义上的交集、并集等操作
>>> s2 = set([2, 3, 4])
>>> s1 & s2
{2, 3}
>>> s1 | s2
{1, 2, 3, 4}
```

set和dict的唯一区别仅在于没有存储对应的value，但是，set的原理和dict一样，所以，同样不可以放入可变对象，因为无法判断两个可变对象是否相等，也就无法保证set内部“不会有重复元素”。试试把list放入set，看看是否会报错。

##### 不可变对象

```python
>>> a = ['c', 'b', 'a'] # 可变对象，比如list，对list进行操作，list内部的内容是会变化的
>>> a.sort()
>>> a
['a', 'b', 'c']
```

```python
>>> a = 'abc' # 不可变对象，比如str，对str进行操作，str内部的内容是不会改变的
>>> b = a.replace('a', 'A')
>>> b
'Abc'
>>> a
'abc'
```

##### 小结

使用key-value存储结构的dict在Python中非常有用，选择不可变对象作为key很重要，最常用的key是字符串。

tuple虽然是不变对象，但试试把`(1, 2, 3)`和`(1, [2, 3])`放入dict或set中，并解释结果。

## 第二天

2019/1/2

### 基本认识2

#### 函数

Python内置了很多有用的函数，通过[Python的官方文档](http://docs.python.org/3/library/functions.html#abs)或在交互式命令行通过`help(abs)`查看帮助。

##### `abs()`

```
>>> abs(-7.8)
7.8
```

```python
>>> abs('a')
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: bad operand type for abs(): 'str' # `str`是错误的参数类型
```

##### `max()`

```
>>> max(2, 3, 1, -5)
3
```

##### `int(),float(),str(),bool(),hex()`

```python
>>> int(12.34)
12
>>> float('12')
12.0
>>> str(1.23)
'1.23'
>>> bool(1)
True
>>> bool()
False
```

##### `a = abs`

```python
>>> a = abs # 变量a指向abs函数
>>> a(-1) # 所以也可以通过a调用abs函数
1
```

##### `def()`

```python
def my_abs(x): #自定义一个求绝对值函数
    if x >= 0:
        return x
    else:
        return -x
```

##### `pass`

```python
def nop():
    pass # 现在还没想好怎么写函数的代码
```

```python
if age >= 18:
    pass # 作为占位符，避免语法错误
```

##### `isinstance()`

```python
def my_abs(x):
    if not isinstance(x, (int, float)): #对参数类型做检查，只允许整数和浮点数类型的参数
        raise TypeError('bad operand type')
    if x >= 0:
        return x
    else:
        return -x
```

##### `return x,y`

```python
import math # 导入math包，并允许后续代码引用math包里的sin、cos等函数

def move(x, y, step, angle=0):
    nx = x + step * math.cos(angle)
    ny = y - step * math.sin(angle)
    return nx, ny
>>> x, y = move(100, 100, 60, math.pi / 6)
>>> print(x, y) # 其实这只是一种假象，Python函数返回的仍然是单一值
151.96152422706632 70.0
```

```python
>>> r = move(100, 100, 60, math.pi / 6)
>>> print(r)
(151.96152422706632, 70.0)
```

原来返回值是一个tuple！但是，在语法上，返回一个tuple可以省略括号，而多个变量可以同时接收一个tuple，按位置赋给对应的值，所以，Python的函数返回多值其实就是返回一个tuple，但写起来更方便。

##### `quadratic`

请定义一个函数`quadratic(a, b, c)`，接收3个参数，返回一元二次方程的两个解。

```python
import math

def quadratic(a,b,c):
    if not isinstance(a,(int,float)):
        raise TypeError('a is not a number,please try again')
    if not isinstance(b,(int,float)):
        raise TypeError('b is not a number,please try again')
    if not isinstance(c,(int,float)):
        raise TypeError('b is not a number,please try again')
    d = b*b - 4*a*c
    if d < 0:
        return 'b*b-4*a*c= ',d,'<0,方程无解'
    else:
        if a == 0:
            if b == 0:
                if c == 0:
                    return '方程解为全体实数'
                else:
                    return '方程无解'
            else:
                x1 = -c/b
                x2 = x1
                return x1,x2
        else:
            x1 = (-b + math.sqrt(d))/(2*a)
            x2 = (-b - math.sqrt(d))/(2*a)
            return x1,x2

a = input('a = ')
a = float(a)
b = input('b = ')
b = float(b)
c = input('c = ')
c = float(c)
print(quadratic(a,b,c))
```

[罗技585虚拟机滚轮失灵](https://blog.csdn.net/baidu_18197725/article/details/82787520)

##### 位置参数`power(x, n)`

```python
def power(x): # 参数x就是一个位置参数
    return x * x
```

```python
def power(x, n): # 参数x和n是两个位置参数
    s = 1
    while n > 0:
        n = n - 1
        s = s * x
    return s
```

##### 默认参数`power(x, n=2)`

```python
def power(x, n=2): #由于经常计算x2，所以可以把第二个参数n的默认值设定为2
    s = 1
    while n > 0:
        n = n - 1
        s = s * x
    return s
```

```python
>>> power(5)
25
>>> power(5, 2) # 调用 power(5) 时，相当于调用 power(5, 2)
25
```

```python
def enroll(name, gender, age=6, city='Beijing'): # 把年龄和城市设为默认参数：
    print('name:', name)
    print('gender:', gender)
    print('age:', age)
    print('city:', city)
```

```python
>>> enroll('Sarah', 'F')
name: Sarah
gender: F
age: 6
city: Beijing

enroll('Bob', 'M', 7) # 只有与默认参数不符的学生才需要提供额外的信息
enroll('Adam', 'M', city='Tianjin')
```

默认参数的坑

```python
def add_end(L=[]): # 先定义一个函数，传入一个list，添加一个`END`再返回
    L.append('END')
    return L
```

```python
>>> add_end() # 当你使用默认参数调用时，一开始结果也是对的
['END']
```

```python
>>> add_end() # 再次调用`add_end()`时，结果就不对了
['END', 'END']
>>> add_end() # 要牢记一点：默认参数必须指向不变对象！不如结果是动态的
['END', 'END', 'END']
```

```python
def add_end(L=None): # 可以用`None`这个不变对象来实现
    if L is None:
        L = []
    L.append('END')
    return L
```

```python
>>> add_end() # 现在，无论调用多少次，都不会有问题
['END']
>>> add_end()
['END']
```

##### 可变参数`calc(*numbers)`

```python
def calc(*numbers): # 定义可变参数和定义一个list或tuple参数相比，仅仅在参数前面加了一个`*`号
    sum = 0
    for n in numbers:
        sum = sum + n * n
    return sum
```

```python
>>> calc(1, 2)
5
>>> calc() # 可以传入任意个参数，包括0个参数
0
```

```python
>>> n = [1, 2, 3] # 如果已经有一个list或者tuple
>>> calc(*n) # 加一个*号，把list或tuple的元素变成可变参数
14
```

##### 关键字参数`person(name, **kw)`

```python
def person(name, age, **kw):
    print('name:', name, 'age:', age, 'other:', kw)
```

```python
>>> person('Michael', 30) #传入0个的关键字参数
name: Michael age: 30 other: {}
            
>>> person('Michael', 45, gender='M', job='Engineer') #传入任意个数的关键字参数
name: Michael age: 45 other: {'gender': 'M', 'job': 'Engineer'}
            
>>> extra = {'city': 'Beijing', 'job': 'Engineer'} #可以先组装出一个dict
>>> person('Jack', 24, city=extra['city'], job=extra['job']) #把dict转换为关键字参数传进去
name: Jack age: 24 other: {'city': 'Beijing', 'job': 'Engineer'}
>>> person('Jack', 24, **extra) #简化的调用写法
name: Jack age: 24 other: {'city': 'Beijing', 'job': 'Engineer'}
```

对`kw`的改动不会影响到函数外的`extra`

##### 命名关键字参数`person(name, *, city)`

```python
def person(name, age, *, city, job): #只接收city和job作为关键字参数
    print(name, age, city, job)
```

```python
>>> person('Jack', 24, city='Beijing', job='Engineer')
Jack 24 Beijing Engineer
```

```python
def person(name, age, *args, city, job): # 如果已经定义了一个可变参数，后面的命名关键字参数就不再需要一个特殊分隔符`*
    print(name, age, 'other:', args, city, job)
```

```python
>>> person('Jack', 24, 'Beijing', 'Engineer') # 由于调用时缺少参数名`city`和`job`，Python解释器把这4个参数均视为位置参数，但`person()`函数仅接受2个位置参数。
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: person() takes 2 positional arguments but 4 were given
```

```python
def person(name, age, *, city='Beijing', job): #简化调用
    print(name, age, city, job)
```

```python
>>> person('Jack', 24, job='Engineer') #由于city具有默认值，调用时可不传入city参数
Jack 24 Beijing Engineer
```

##### 参数组合`f1(a, *args, **kw)`

5种参数可以组合使用。但注意定义的顺序：必选参数、默认参数、可变参数、命名关键字参数和关键字参数。

```python
def f1(a, b, c=0, *args, **kw):
    print('a =', a, 'b =', b, 'c =', c, 'args =', args, 'kw =', kw)

def f2(a, b, c=0, *, d, **kw):
    print('a =', a, 'b =', b, 'c =', c, 'd =', d, 'kw =', kw)
```

```python
>>> f1(1, 2)
a = 1 b = 2 c = 0 args = () kw = {}
>>> f1(1, 2, 3, 'a', 'b', x=99) # Python解释器自动按照参数位置和参数名把对应的参数传进去
a = 1 b = 2 c = 3 args = ('a', 'b') kw = {'x': 99}
>>> f2(1, 2, d=99, ext=None)
a = 1 b = 2 c = 0 d = 99 kw = {'ext': None}
```

最神奇的是通过一个tuple和dict，你也可以调用上述函数：

```python
>>> args = (1, 2, 3, 4)
>>> kw = {'d': 99, 'x': '#'}
>>> f1(*args, **kw)
a = 1 b = 2 c = 3 args = (4,) kw = {'d': 99, 'x': '#'}
>>> args = (1, 2, 3)
>>> kw = {'d': 88, 'x': '#'}
>>> f2(*args, **kw)
a = 1 b = 2 c = 3 d = 88 kw = {'x': '#'}
```

所以，对于任意函数，都可以通过类似`func(*args, **kw)`的形式调用它，无论它的参数是如何定义的。

##### 递归函数

```python
def fact(n):
    if n==1:
        return 1
    return n * fact(n - 1)
```

```python
>>> fact(5)
120
```

```python
===> fact(5) # 根据函数定义看到计算过程
===> 5 * fact(4)
===> 5 * (4 * fact(3))
===> 5 * (4 * (3 * fact(2)))
===> 5 * (4 * (3 * (2 * fact(1))))
===> 5 * (4 * (3 * (2 * 1)))
===> 5 * (4 * (3 * 2))
===> 5 * (4 * 6)
===> 5 * 24
===> 120
```

##### 尾递归

```python
def fact(n):
    return fact_iter(n, 1)

def fact_iter(num, product):
    if num == 1:
        return product
    return fact_iter(num - 1, num * product)
```

可以看到，`return fact_iter(num - 1, num * product)`仅返回递归函数本身，`num - 1`和`num * product`在函数调用前就会被计算，不影响函数调用。

`fact(5)`对应的`fact_iter(5, 1)`的调用如下：

```python
===> fact_iter(5, 1)
===> fact_iter(4, 5)
===> fact_iter(3, 20)
===> fact_iter(2, 60)
===> fact_iter(1, 120)
===> 120
```

尾递归调用时，如果做了优化，栈不会增长，因此，无论多少次调用也不会导致栈溢出。

遗憾的是，大多数编程语言没有针对尾递归做优化，Python解释器也没有做优化，所以，即使把上面的`fact(n)`函数改成尾递归方式，也会导致栈溢出。

```python
def hanoi(n, a, b, c): # 汉诺塔
    if n == 1:
        print(a, '-->', c)
    else:
        hanoi(n-1, a, c, b)
        hanoi(1, a, b, c)
        hanoi(n-1, b, a, c)

hanoi(3, 'A', 'B', 'C')
```

#### 高级特性

##### 切片 Slice

```python
>>> L = ['Michael', 'Sarah', 'Tracy', 'Bob', 'Jack']

>>> L[0:3]
['Michael', 'Sarah', 'Tracy']
>>> L[:3] #第一个索引是0，可以省略
['Michael', 'Sarah', 'Tracy']
>>> L[-2:]
['Bob', 'Jack']
>>> L[-2:-1] #记住倒数第一个元素的索引是-1
['Bob']
```

```python
>>> L = list(range(100)) #创建一个0-99的数列

>>> L[:10:2] #前10个数，每两个取一个
[0, 2, 4, 6, 8]
>>> L[-10:] #后10个数
[90, 91, 92, 93, 94, 95, 96, 97, 98, 99]
>>> L[::5] #所有数，每5个取一个
[0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95]
>>> L[:] #复制一个list
[0, 1, 2, 3, ..., 99]
```

```python
>>> (0, 1, 2, 3, 4, 5)[:3] # tuple也是一种list, 也可以用切片操作，只是操作的结果仍是tuple
(0, 1, 2)
```

```python
>>> 'ABCDEFG'[:3] # 字符串'xxx'也可以看成是一种list，也可以用切片操作
'ABC'             # 只是操作结果仍是字符串
>>> 'ABCDEFG'[::2]
'ACEG'
```

`substring` 其实目的就是对字符串切片

##### `trim()`

```python
#trim() 去除字符串首尾的空格
def trim(s):
    print('s=[%s]' %s)
    if len(s)==0:
        return s
    b=0
    while len(s)>0 and s[b]==' ': #去除字符串首的空格
        s=s[b+1:]
    print(s)
    e=-1
    while len(s)>0 and s[e]==' ': #去除字符串尾的空格
        s=s[:e]
    print(s,'\n')

    return s
```

##### 迭代 Iteration

通过`for`循环来遍历这个list或tuple，这种遍历我们称为迭代

Python迭代是通过`for ... in`来完成的，其它比如C语言，迭代list是通过下标完成的，比如Java代码：

```java
for (i=0; i<list.length; i++) {
    n = list[i];
}
```

```python
>>> d = {'a': 1, 'b': 2, 'c': 3} #Python中无论有无下标，都可以迭代，比如dict
>>> for key in d:
...     print(key) #默认dict迭代的是key
a
c #因为dict的存储不是顺序排列
b #所以迭代结果顺序很可能不一样
>>> for value in d.values() #修改dict迭代value
...     print(value)

>>> for k, v in d.items() #修改dict迭代key和value
...     print(value)
```

```python
>>> for ch in 'ABC':
...     print(ch)
A
B
C
```

`Iterable`

```python
>>> from collections import Iterable  #判断一个对象是可迭代对象
>>> isinstance('abc', Iterable) # str是否可迭代
True
>>> isinstance([1,2,3], Iterable) # list是否可迭代
True
>>> isinstance(123, Iterable) # 整数是否可迭代
False
```

`enumerate`

```python
>>> for i, value in enumerate(['A', 'B', 'C']): #把一个list变成索引-元素对
...     print(i, value)
...
0 A
1 B
2 C
```

##### `MinandMax()`

```python
# -*- coding: utf-8 -*-
def MinAndMax(L):
    if len(L)==0:
        return (None, None)
    else:
        max=L[0]
        min=L[0]
        for num in L:
            if num>max:
                max=num
            if num<min:
                min=num
        return (min,max)
L=[7, 1, 3, 9, 5]
print('Min =',MinAndMax(L)[0],'Max =',MinAndMax(L)[1])
```

##### 列表生成式 List Comprehensions

```python
>>> list(range(1, 11))
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
```

```python
>>> [x * x for x in range(1, 11)] #生成[1x1, 2x2, ..., 10x10]
[1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
```

```python
>>> [x * x for x in range(1, 11) if x % 2 == 0] #筛选出仅偶数的平方
[4, 16, 36, 64, 100]
```

```python
>>> [m + n for m in 'ABC' for n in 'XYZ'] #使用两层循环，可以生成全排列
['AX', 'AY', 'AZ', 'BX', 'BY', 'BZ', 'CX', 'CY', 'CZ']
```

```python
>>> import os # 导入os模块，模块的概念后面讲到
>>> [d for d in os.listdir('.')] # os.listdir可以列出文件和目录
['.emacs.d', '.ssh', '.Trash', 'Adlm', 'Applications', 'Desktop', 'Documents', 'Downloads', 'Library', 'Movies', 'Music', 'Pictures', 'Public', 'VirtualBox VMs', 'Workspace', 'XCode']
```

```python
>>> d = {'x': 'A', 'y': 'B', 'z': 'C' }
>>> for k, v in d.items(): #同时迭代key和value
...     print(k, '=', v)
...
y = B
x = A
z = C
```

```python
>>> d = {'x': 'A', 'y': 'B', 'z': 'C' } #用两个变量来生成list
>>> [k + '=' + v for k, v in d.items()]
['y=B', 'x=A', 'z=C']
```

```python
>>> L = ['Hello', 'World', 'IBM', 'Apple'] #所有的字符串变成小写
>>> [s.lower() for s in L]
['hello', 'world', 'ibm', 'apple']
```

##### `isinstance()`

```python
L1 = ['Hello', 'World', 18, 'Apple', None]
L2 = [s.lower() for s in L1 if isinstance(s, str)]
print(L2)
```

##### 生成器 generator

```python
>>> L = [x * x for x in range(10)]
>>> L
[0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
>>> g = (x * x for x in range(10)) #第1种方法:只要把一个列表生成式的[]改成()
>>> g  #一边循环一边计算的机制
<generator object <genexpr> at 0x1022ef630>
```

创建`L`和`g`的区别仅在于最外层的`[]`和`()`，`L`是一个list，而`g`是一个generator

```python
g = (x * x for x in range(10))
for n in g:
    print(n)
```

```python
def fib(max): #斐波拉契数列 Fibonacci
    n, a, b = 0, 0, 1
    while n < max:
#        print(b) #函数打印
        yield b  #第2种方法:包含yield关键字的特殊函数，是一个generator：
        a, b = b, a + b
        n = n + 1
    return 'done'
for n in fib(9):
    print(n)
```

##### `triangles()`

```python
def triangles(n):  # (n-1)层杨辉三角
    L = [1]  # 定义一个[1]的列表
    while len(L) < n:
        yield L  # 下次循环直接从此开始!yeild是如此神奇
        L.append(0)  # 现在生成一个新的列表, 就是在列表L后面加1
        L = [L[i - 1] + L[i] for i in range(len(L))]
        
# range(len(N))=[0,1],
# N = [N[i-1]+N[i] for i in [0,1]] 
# N = [N[0-1]+N[0] , N[1-1]+N[1]]
# N = [0+1 , 1+0] = [1,1] 
# 这样，杨辉三角的第二行就出来啦！


for n in triangles(9):
    print(n)
```

##### 迭代器 Iterator

凡是可作用于`for`循环的对象都是`Iterable`类型；

一类是集合数据类型，如`list`、`tuple`、`dict`、`set`、`str`等；

一类是`generator`，包括生成器和带`yield`的generator function

```python
>>> from collections import Iterable # 判断一个对象是否是Iterable对象
>>> isinstance([], Iterable) # list 可以
True
>>> isinstance({}, Iterable) # tuple 可以
True
>>> isinstance('abc', Iterable) # str 可以
True
>>> isinstance((x for x in range(10)), Iterable) # generator 可以
True
>>> isinstance(100, Iterable)
False
```

凡是可作用于`next()`函数的对象都是`Iterator`类型，它们表示一个惰性计算的序列；

```python
>>> from collections import Iterator # 判断一个对象是否是Iterator对象
>>> isinstance((x for x in range(10)), Iterator)
True
>>> isinstance([], Iterator) # list虽然是Iterable，却不是Iterator
False
>>> isinstance({}, Iterator) # dict虽然是Iterable，却不是Iterator
False
>>> isinstance('abc', Iterator) # str虽然是Iterable，却不是Iterator
False
```

##### `iter()`

```python
>>> isinstance(iter([]), Iterator) # 把list、dict、str等Iterable变成Iterator
True
>>> isinstance(iter('abc'), Iterator)
True
```

`Iterator`甚至可以表示一个无限大的数据流，例如全体自然数。而使用list是永远不可能存储全体自然数的。

Python的`for`循环本质上就是通过不断调用`next()`函数实现的，例如：

```python
for x in [1, 2, 3, 4, 5]:
    pass
```

```python
# 首先获得Iterator对象:
it = iter([1, 2, 3, 4, 5])
# 循环:
while True:
    try:
        # 获得下一个值:
        x = next(it)
    except StopIteration:
        # 遇到StopIteration就退出循环
        break
```

#### 函数式编程

函数式编程的一个特点就是，允许把函数本身作为参数传入另一个函数，还允许返回一个函数！

Python对函数式编程提供部分支持。由于Python允许使用变量，因此，Python不是纯函数式编程语言。

##### 高阶函数英文 Higher-order function

##### 变量指向函数

```
>>> f = abs
>>> f(-10)
10
```

##### 函数名指向变量

```python
>>> abs = 10
>>> abs(-10) # abs已经指向一个整数10！若恢复abs函数，需重启Python交互环境
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: 'int' object is not callable
```

注：由于`abs`函数实际上是定义在`import builtins`模块中的，所以要让修改`abs`变量的指向在其它模块也生效，要用`import builtins; builtins.abs = 10`。

##### 传入函数

```python
def add(x, y, f): # 函数作为参数，这种函数就称之为高阶函数
    return f(x) + f(y)

add(-5, 6, abs) # 参数x，y和f分别是-5，6和函数abs
11
```

##### `map()`

函数接收两个参数，一个是函数，一个是`Iterable`，`map`将传入的函数依次作用到序列的每个元素，并把结果作为新的`Iterator`返回。

```python
>>> list(map(str, [1, 2, 3, 4, 5, 6, 7, 8, 9])) # 把这个list所有数字转为字符串
['1', '2', '3', '4', '5', '6', '7', '8', '9']
```

##### `reduce()`

一个函数作用在一个序列上，把结果继续和序列的下一个元素做累积计算，其效果就是：

```python
reduce(f, [x1, x2, x3, x4]) = f(f(f(x1, x2), x3), x4)
```

```python
>>> from functools import reduce
>>> def fn(x, y):
...     return x * 10 + y
...
>>> reduce(fn, [1, 3, 5, 7, 9]) # 变成整数
13579
```

`str2int()`

```python
from functools import reduce

DIGITS = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4,
          '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}

def str2int(s):  # 把str转换为int
    def fn(x, y):
        return x * 10 + y

    def char2num(s):
        return DIGITS[s]
    return reduce(fn, map(char2num, s))

print(str2int('23'))
```

```python
from functools import reduce

DIGITS = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4,
          '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}

def char2num(s):
    return DIGITS[s]

def str2int(s):
    return reduce(lambda x, y: x * 10 + y, map(char2num, s)) # 用lambda函数进一步简化

print(str2int('23'))
```

```python
from functools import reduce

# 规范英文名字
def normalize(name):
    return name.capitalize()

# 测试:
L1 = ['adam', 'LISA', 'barT']
L2 = list(map(normalize, L1))
print(L2)

# 编写一个prod()函数，可以接受一个list并利用reduce()求积
def prod(L):
    return reduce(lambda x, y: x * y, L)

# 测试:
print('3 * 5 * 7 * 9 =', prod([3, 5, 7, 9]))
if prod([3, 5, 7, 9]) == 945:
    print('测试成功!')
else:
    print('测试失败!')

# 把字符串'123.456'转换成浮点数123.456
def char2num(s):
    return {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}[s]

def str2int(s):
    return reduce(lambda x, y: x * 10 + y, map(char2num, s))

def fn(x, y):
    return x * 10 + y

def str2float(s):
    if '.' in s:
        i = s.index('.')
        s = s.replace('.', '')
        x = reduce(fn, map(char2num, s)) / (10 ** i)
    return x

# 测试:
print(str2float('2.33'))
```

##### `filter()`

接收一个函数和一个序列，用于过滤序列

```python
def is_odd(n):
    return n % 2 == 1
def not_empty(s):
	return s and s.strip()

list(filter(is_odd, [1, 2, 4, 5, 6, 9, 10, 15])) # 过滤偶数
# 结果: [1, 5, 9, 15]
list(filter(not_empty, ['A', '', 'B', None, 'C', '  '])) # 过滤空格
# 结果: ['A', 'B', 'C']
```

`filter()`函数返回的是一个`Iterator`，也就是一个惰性序列，所以要强迫`filter()`完成计算结果，需要用`list()`函数获得所有结果并返回list。

用filter求素数

```python
def _odd_iter(): # 定义一个无限奇数序列
    n = 1
    while True:
        n = n + 2
        yield n
```

```python
def _not_divisible(n): # 筛选函数
    return lambda x: x % n > 0
```

```python
def primes(): # 最后，定义一个生成器，不断返回下一个素数
    yield 2
    it = _odd_iter() # 初始序列
    while True:
        n = next(it) # 返回序列的第一个数
        yield n
        it = filter(_not_divisible(n), it) # 构造新序列
```

由于`primes()`也是一个无限序列，所以调用时需要设置一个退出循环的条件：

```python
# 打印1000以内的素数:
for n in primes():
    if n < 1000:
        print(n)
    else:
        break
```

```python
def is_palindrome(n):
    return str(n) == str(n)[::-1]

output = filter(is_palindrome, range(1, 1000)) # 筛选出1~1000之间的回文数
print('1~1000:', list(output))
if list(filter(is_palindrome, range(1, 200))) == [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22,
                                                 33, 44, 55, 66, 77, 88, 99, 101, 111,
                                                 121, 131, 141, 151, 161, 171, 181, 191]:
    print('测试成功!')
else:
    print('测试失败!')
```

##### `sorted()`

```python
>>> sorted([36, 5, -12, 9, -21]) # 可以对list进行排序
[-21, -12, 5, 9, 36]
```

```python
>>> sorted([36, 5, -12, 9, -21], key=abs) # 按绝对值大小排序
[5, 9, -12, -21, 36]
```

```python
>>> sorted(['bob', 'about', 'Zoo', 'Credit'])
['Credit', 'Zoo', 'about', 'bob'] # 默认是按照ASCII的大小比较，Z会排在小写字母a的前面
```

```python
>>> sorted(['bob', 'about', 'Zoo', 'Credit'], key=str.lower) # 忽略大小写的排序
['about', 'bob', 'Credit', 'Zoo']
```

```python
>>> sorted(['bob', 'about', 'Zoo', 'Credit'], key=str.lower, reverse=True) # 反向排序
['Zoo', 'Credit', 'bob', 'about']
```

```python
L = [('Bob', 75), ('Adam', 92), ('Bart', 66), ('Lisa', 88)]

def by_name(t):
    return t[0].capitalize()

def by_score(t):
    return t[1]


L1 = sorted(L, key=by_name)
print(L1)
L2 = sorted(L, key=by_score, reverse=True)
print(L2)
```

##### 返回函数

```
def lazy_sum(*args):
    def sum():
        ax = 0
        for n in args:
            ax = ax + n
        return ax
    return sum
```

当我们调用`lazy_sum()`时，返回的并不是求和结果，而是求和函数：

```
>>> f = lazy_sum(1, 3, 5, 7, 9)
>>> f
<function lazy_sum.<locals>.sum at 0x101c6ed90>
```

调用函数`f`时，才真正计算求和的结果：

```
>>> f()
25
```

在这个例子中，我们在函数`lazy_sum`中又定义了函数`sum`，并且，内部函数`sum`可以引用外部函数`lazy_sum`的参数和局部变量，当`lazy_sum`返回函数`sum`时，相关参数和变量都保存在返回的函数中，这种称为“闭包（Closure）”的程序结构拥有极大的威力。

请再注意一点，当我们调用`lazy_sum()`时，每次调用都会返回一个新的函数，即使传入相同的参数：

```
>>> f1 = lazy_sum(1, 3, 5, 7, 9)
>>> f2 = lazy_sum(1, 3, 5, 7, 9)
>>> f1==f2
False
```

`f1()`和`f2()`的调用结果互不影响。

### 闭包

注意到返回的函数在其定义内部引用了局部变量`args`，所以，当一个函数返回了一个函数后，其内部的局部变量还被新函数引用，所以，闭包用起来简单，实现起来可不容易。

另一个需要注意的问题是，返回的函数并没有立刻执行，而是直到调用了`f()`才执行。我们来看一个例子：

```
def count():
    fs = []
    for i in range(1, 4):
        def f():
             return i*i
        fs.append(f)
    return fs

f1, f2, f3 = count()
```

在上面的例子中，每次循环，都创建了一个新的函数，然后，把创建的3个函数都返回了。

你可能认为调用`f1()`，`f2()`和`f3()`结果应该是`1`，`4`，`9`，但实际结果是：

```
>>> f1()
9
>>> f2()
9
>>> f3()
9
```

全部都是`9`！原因就在于返回的函数引用了变量`i`，但它并非立刻执行。等到3个函数都返回时，它们所引用的变量`i`已经变成了`3`，因此最终结果为`9`。

 返回闭包时牢记一点：返回函数不要引用任何循环变量，或者后续会发生变化的变量。

如果一定要引用循环变量怎么办？方法是再创建一个函数，用该函数的参数绑定循环变量当前的值，无论该循环变量后续如何更改，已绑定到函数参数的值不变：

```
def count():
    def f(j):
        def g():
            return j*j
        return g
    fs = []
    for i in range(1, 4):
        fs.append(f(i)) # f(i)立刻被执行，因此i的当前值被传入f()
    return fs
```

再看看结果：

```
>>> f1, f2, f3 = count()
>>> f1()
1
>>> f2()
4
>>> f3()
9
```

缺点是代码较长，可利用lambda函数缩短代码。

### 练习

利用闭包返回一个计数器函数，每次调用它返回递增整数：