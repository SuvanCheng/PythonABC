# Python

多谢 @[雪峰](https://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/001431676242561226b32a9ec624505bb8f723d0027b3e7000)



## 第一天

### 

### 基本认识

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

Python对`bytes`类型的数据用带`b`前缀的单引号或双引号表示：

```python
x = b'ABC'
```

区分`'ABC'`和`b'ABC'`，前者是`str`，后者是`bytes`，后者只占用一个字节



`str`变为`bytes`，需要用`encode()`方法：

```python
>>> print('中文'.encode('utf-8'))
b'\xe4\xb8\xad\xe6\x96\x87'
>>> print('ABC'.encode('ascii'))
b'ABC'
>>> print('中文'.encode('ascii'))
ASCII字符无法表示中文
```

`bytes`变为`str`，需要用`decode()`方法：

```python
>>> print(b'\xe4\xb8\xad\xe6\x96\x87'.decode('utf-8'))
中文
>>> print(b'\xe4\xb8\xad\xe6\x96'.decode('utf-8', errors='ignore'))
中
```

计算`str`包含多少个字符，可以用`len()`函数：

```
>>> print(len("ABC"))
3
>>> print(len('ABC'))
3
>>> print(len(b'ABC'))
3
>>> print(len(b'\xe4\xb8\xad\xe6\x96\x87'))
6
>>> print(len('中文'))
2
>>> print(len('中文'.encode('utf-8')))
6
```

可见，1个中文字符经过UTF-8编码后通常会占用3个字节，而1个英文字符只占用1个字节。

#### 占位符 %?

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

##### list

list是一种有序的集合，可以随时添加和删除其中的元素。

列出班里所有同学的名字，就可以用一个list表示：

```python
>>> classmates = ['Michael', 'Bob', 'Tracy']
>>> classmates
['Michael', 'Bob', 'Tracy']
```

`len()`函数可以获得list元素的个数：

```python
>>> len(classmates)
3
```

用索引来访问list中每一个位置的元素，记得索引是从`0`开始的：

```
>>> classmates[0]
'Michael'
>>> classmates[1]
'Bob'
>>> classmates[2]
'Tracy'
```

还可以用`-1`做索引，直接获取最后一个元素，以此类推，可以获取倒数第2个、倒数第3个：

```
>>> classmates[-1]
'Tracy'
>>> classmates[-2]
'Bob'
>>> classmates[-3]
'Michael'
```

追加元素到末尾：

```
>>> classmates.append('Adam')
>>> classmates
['Michael', 'Bob', 'Tracy', 'Adam']
```

插入到指定的位置，比如索引号为`1`的位置：

```
>>> classmates.insert(1, 'Jack')
>>> classmates
['Michael', 'Jack', 'Bob', 'Tracy', 'Adam']
```

删除`list`末尾的元素，用`pop()`方法：

```
>>> classmates.pop()
'Adam'
>>> classmates
['Michael', 'Jack', 'Bob', 'Tracy']
```

删除指定位置的元素，用`pop(i)`方法，其中`i`是索引位置：

```
>>> classmates.pop(1)
'Jack'
>>> classmates
['Michael', 'Bob', 'Tracy']
```

替换某个元素，可以直接赋值给对应的索引位置：

```
>>> classmates[1] = 'Sarah'
>>> classmates
['Michael', 'Sarah', 'Tracy']
```

list里面的元素的数据类型可以不同：

```
>>> L = ['Apple', 123, True]
```

list元素也可以是另一个list：

```
>>> s = ['python', 'java', ['asp', 'php'], 'scheme']
>>> len(s)
4
```

要注意`s`只有4个元素，其中`s[2]`又是一个list，如果拆开写就更容易理解了：

```
>>> p = ['asp', 'php']
>>> s = ['python', 'java', p, 'scheme']
```

要拿到`'php'`可以写`p[1]`或者`s[2][1]`，因此`s`可以看成是一个二维数组，类似的还有三维、四维……数组，不过很少用到。

如果一个list中一个元素也没有，就是一个空的list，它的长度为0：

```
>>> L = []
>>> len(L)
0
```

##### tuple

另一种有序列表叫元组：tuple。tuple和list非常类似，但是tuple一旦初始化就不能修改，比如同样是列出同学的名字：

```
>>> classmates = ('Michael', 'Bob', 'Tracy')
```

现在，classmates这个tuple不能变了，它也没有`append()`，`insert()`这样的方法。其他获取元素的方法和list是一样的，你可以正常地使用`classmates[0]`，`classmates[-1]`，但不能赋值成另外的元素。

不可变的tuple有什么意义？因为tuple不可变，所以代码更安全。如果可能，能用tuple代替list就尽量用tuple。

tuple的陷阱：当你定义一个tuple时，在定义的时候，tuple的元素就必须被确定下来，比如：

```
>>> t = (1, 2)
>>> t
(1, 2)
```

如果要定义一个空的tuple，可以写成`()`：

```
>>> t = ()
>>> t
()
```

但是，要定义一个只有1个元素的tuple，如果你这么定义：

```
>>> t = (1)
>>> t
1
```

定义的不是tuple，是`1`这个数！这是因为括号`()`既可以表示tuple，又可以表示数学公式中的小括号，这就产生了歧义，因此，Python规定，这种情况下，按小括号进行计算，计算结果自然是`1`。

所以，**只有1个元素的tuple定义时必须加一个逗号`,`，来消除歧义：**

```
>>> t = (1,)
>>> t
(1,)
```

Python在显示只有1个元素的tuple时，也会加一个逗号`,`，以免你误解成数学计算意义上的括号。

最后来看一个“可变的”tuple：

```
>>> t = ('a', 'b', ['A', 'B'])
>>> t[2][0] = 'X'
>>> t[2][1] = 'Y'
>>> t
('a', 'b', ['X', 'Y'])
```

这个tuple定义的时候有3个元素，分别是`'a'`，`'b'`和一个list。不是说tuple一旦定义后就不可变了吗？怎么后来又变了？

别急，我们先看看定义的时候tuple包含的3个元素：

![tuple-0](https://cdn.liaoxuefeng.com/cdn/files/attachments/001387269705541ad608276b6f7426ca59b8c2b19947243000/0)

当我们把list的元素`'A'`和`'B'`修改为`'X'`和`'Y'`后，tuple变为：

![tuple-1](https://cdn.liaoxuefeng.com/cdn/files/attachments/001387269768140c7d5ca167342402989dfc75343fe900b000/0)

表面上看，tuple的元素确实变了，但其实变的不是tuple的元素，而是list的元素。tuple一开始指向的list并没有改成别的list，所以，tuple所谓的“不变”是说，tuple的每个元素，指向永远不变。即指向`'a'`，就不能改成指向`'b'`，指向一个list，就不能改成指向其他对象，但指向的这个list本身是可变的！

理解了“指向不变”后，要创建一个内容也不变的tuple怎么做？那就必须保证tuple的每一个元素本身也不能变。

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

如果`if`判断是`True`，就把缩进的语句执行了，否则，什么也不做。这就是**缩进规则**

```
age = 20
if age >= 18:
    print('your age is', age)
    print('adult')
```

如果`if`判断是`False`，不要执行`if`的内容，去把`else`执行了：

```
age = 3
if age >= 18:
    print('your age is', age)
    print('adult')
else:
    print('your age is', age)
    print('teenager')
```

注意不要少写了冒号`:`

更细致的判断

`elif`

```python
age = 3
if age >= 18:
    print('adult')
elif age >= 6:
    print('teenager')
else:
    print('kid')
```

`if`语句执行有个特点，它是从上往下判断，如果在某个判断上是`True`，把该判断对应的语句执行后，就忽略掉剩下的`elif`和`else`，此外`if`判断条件还可以简写，比如写：

```
if x:
    print('True')
```

只要`x`是非零数值、非空字符串、非空list等，就判断为`True`，否则为`False`。

##### input

有问题的条件判断

```python
s = input('birth: ')
birth = int(s) #input()返回的是str，str不能和整数比较，必须先把str转换成整数
if birth < 2000:
    print('00前')
else:
    print('00后')
```

##### 练习

小明身高1.75，体重80.5kg。请根据BMI公式（体重除以身高的平方）帮小明计算他的BMI指数，并根据BMI指数：

- 低于18.5：过轻
- 18.5-25：正常
- 25-28：过重
- 28-32：肥胖
- 高于32：严重肥胖

```python
h = input('height: ')
h = float(h)
w = input('weight:')
w = float(w)
s = (w/h)/h
print(s)
if s < 18.5:
    print('slim')
elif s < 25:
    print('handsome')
elif s<28:
    print('fat')
elif s<32:
    print('hamburger')
else:
    print('incorrigible')
```

#### 循环

##### for...in

```
names = ['Michael', 'Bob', 'Tracy']
for n in names:
    print(n)
```

执行这段代码，会依次打印`names`的每一个元素：

```
Michael
Bob
Tracy
```

`range()`函数，可以生成一个整数序列，再通过`list()`函数可以转换为list。

```
>>> list(range(5))
[0, 1, 2, 3, 4]
```

`range(101)`就可以生成0-100的整数序列，计算如下：

```python
sum = 0
for x in range(101):
    sum = sum + x
print(sum)
```

##### while

```python
sum = 0
n = 100
while n > 0:
    sum = sum + n
    n = n - 1
print(sum)
```

在循环内部变量`n`不断自减，直到变为`-1`时，不再满足while条件，循环退出。

##### 练习

```python
L = ['Bart', 'Lisa', 'Adam']
for n in L:
    print('Hello,',n)
```

##### break

```python
n = 1
while n <= 100:
    if n > 10: # 当n = 11时，条件满足，执行break语句
        break # break语句会结束当前循环
    print(n)
    n = n + 1
print('END')
```

##### continue

在循环过程中，也可以通过`continue`语句，跳过当前的这次循环，直接开始下一次循环。

```
n = 0
while n < 10:
    n = n + 1
    print(n)
```

上面的程序可以打印出1～10。但是，如果我们想只打印奇数，可以用`continue`语句跳过某些循环：

```
n = 0
while n < 10:
    n = n + 1
    if n % 2 == 0: # 如果n是偶数，执行continue语句
        continue # continue语句会直接继续下一轮循环，后续的print()语句不会执行
    print(n)
```

执行上面的代码可以看到，打印的不再是1～10，而是1，3，5，7，9。

可见`continue`的作用是提前结束本轮循环，并直接开始下一轮循环。

##### 小结

循环是让计算机做重复任务的有效的方法。

`break`语句可以在循环过程中直接退出循环，而`continue`语句可以提前结束本轮循环，并直接开始下一轮循环。这两个语句通常都*必须*配合`if`语句使用。

*要特别注意*，不要滥用`break`和`continue`语句。`break`和`continue`会造成代码执行逻辑分叉过多，容易出错。大多数循环并不需要用到`break`和`continue`语句，上面的两个例子，都可以通过改写循环条件或者修改循环逻辑，去掉`break`和`continue`语句。

有些时候，如果代码写得有问题，会让程序陷入“死循环”，也就是永远循环下去。这时可以用`Ctrl+C`退出程序，或者强制结束Python进程。

请试写一个死循环程序。