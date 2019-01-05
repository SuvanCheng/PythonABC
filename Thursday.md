# PythonABC

多谢 @[雪峰](https://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/001431676242561226b32a9ec624505bb8f723d0027b3e7000)

<p align="right">
    🚩 <a href="README.md">第一、二天</a>
</p>

## 第三天

### 快捷键

`ctrl+/`多行代码注释
`shift+F6`批量修改变量名

### 模块

```python
mycompany # 按目录来组织模块的方法，称为包（Package）
 ├─ web # 模块名就是`mycompany.web`
 │  ├─ __init__.py # 这个文件是必须存在的，否则，Python就把这个目录当成普通目录
 │  ├─ utils.py
 │  └─ www.py # 模块名就是`mycompany.web.www`
 ├─ __init__.py # 模块名就是`mycompany`
 ├─ abc.py # 模块名就是`mycompany.abc`
 └─ xyz.py
```

内置函数 [Built-in Functions](https://docs.python.org/3/library/functions.html)

#### `sys`

```python
#!/usr/bin/env python3 # 让这个`hello.py`文件直接在Unix/Linux/Mac上运行
# -*- coding: utf-8 -*- # 表示.py文件本身使用标准UTF-8编码

' a test module ' # 文档注释：任何模块代码的第一个字符串都被视为模块的文档注释

__author__ = 'Michael Liao' # 便于开源后别人瞻仰你的大名

import sys  # 导入`sys`模块

def test():
    args = sys.argv # `sys`模块有一个`argv`变量
    if len(args)==1: # `argv`至少有一个元素，因为第一个参数永远是该.py文件的名称
        print('Hello, world!')
    elif len(args)==2:
        print('Hello, %s!' % args[1])
    else:
        print('Too many arguments!')

if __name__=='__main__':
    test()
```

#### `_xxx`

```python
def _private_1(name): # 非公开变量（或函数），不应该被直接引用
    return 'Hello, %s' % name

def _private_2(name):
    return 'Hi, %s' % name

def greeting(name): # 公开`greeting()`函数
    if len(name) > 3:
        return _private_1(name)
    else:
        return _private_2(name)
```

#### `pip`

```
pip install Pillow
```

#### 模块搜索路径

当我们试图加载一个模块时，默认情况下，Python解释器会搜索当前目录、所有已安装的内置模块和第三方模块对应的.py文件，搜索路径存放在`sys`模块的`path`变量中：

```python
>>> import sys
>>> sys.path
['', '/Library/Frameworks/Python.framework/Versions/3.6/lib/python36.zip', '/Library/Frameworks/Python.framework/Versions/3.6/lib/python3.6', ..., '/Library/Frameworks/Python.framework/Versions/3.6/lib/python3.6/site-packages']
```

```python
>>> import sys
>>> sys.path.append('/Users/michael/my_py_scripts') # 接修改`sys.path`，添加要搜索的目录
```

### 面向对象 OOP

```python
class Student(object): # 类（Class）

    def __init__(self, name, score):
        self.name = name # 属性（Property）
        self.score = score # 属性（Property）

    def print_score(self): # 对象的方法（Method）
        print('%s: %s' % (self.name, self.score))
```

```python
bart = Student('Bart Simpson', 59) # 实例（Instance）
lisa = Student('Lisa Simpson', 87)
bart.print_score()
lisa.print_score()
```

#### [类和实例](https://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/001431864715651c99511036d884cf1b399e65ae0d27f7e000)

##### `class`

```python
class Student(object): # 类名`Student`

    def __init__(self, name, score): # `__init__`前后分别有两个下划线！！！
        							 # `__init__`方法的第一个参数永远是`self`
        self.name = name
        self.score = score

    def print_score(self): # 打印是在`Student`类的内部定义的，这些数据和逻辑被“封装”起来了
        print('%s:%s' % (self.name, self.score))

    def get_grade(self): # 可以随时在类中添加新的逻辑
        if self.score >= 90:
            return 'A'
        elif self.score >= 60:
            return 'B'
        else:
            return 'C'
```

##### `instance`

```python
bart = Student('Bart Simpson', 59) # 创建实例bart时就不能传入空的参数
lisa = Student('Lisa Vivien', 99)
```

```python
print(bart.name,':',str(bart.score))
# Bart Simpson:59
```

##### `Method`

```python
bart.print_score()
# Bart Simpson:59

print(lisa.name, lisa.get_grade())
# Lisa Vivien A
```

其它

```python
bart.gender = 'female' # 给实例`bart`绑定一个新的属性`gender`
print(bart.gender)
# female
```

#### 访问限制

##### `__name`

```python
class Student(object):

    def __init__(self, name, score):
        self.__name = name # 定义为私有变量，无法使用`Student.__name`
        self.__score = score

    def get_name(self): # 通过增加方法，给予外部代码访问name的机会
        return self.__name

    def get_score(self):
        return self.__score

    def print_score(self):
        print('%s: %s' % (self.__name, self.__score))

    def set_score(self, score): # 通过增加方法，给予外部代码修改score的机会
        if 0 <= score <= 100:
            self.__score = score
        else:
            raise ValueError('bad score')


bart = Student('Bart Simpson', 49)
lisa = Student('Lisa Vivien', 99)
bart.score = 99
bart.print_score()
# Bart Simpson: 49
bart.set_score(99)
bart.print_score()
# Bart Simpson: 99
```

#### 继承与多态

##### `Subclass`

```python
class Animal(object):
    def run(self):
        print('Animal is running...')
        
class Dog(Animal):
    pass

class Cat(Animal):
    pass
```

```python
class Dog(Animal):

    def eat(self): # 当然，也可以对子类增加一些方法
        print('Eating meat...')
        
    def run(self): # 子类覆盖父类`run()`:多态!
        print('Dog is running...')
```

```python
a = list() # a是list类型
b = Animal() # b是Animal类型
c = Dog() # c是Dog类型

>>> isinstance(a, list)
True
>>> isinstance(b, Animal)
True
>>> isinstance(c, Dog)
True
>>> isinstance(c, Animal)
True
```

要理解多态的好处，我们还需要再编写：

```python
def run_twice(animal): # 定义一个接受`Animal`类型变量的函数
    animal.run()
    animal.run()
    
    
>>> run_twice(Dog())
Dog is running...
Dog is running...

class Tortoise(Animal):
    def run(self):
        print('Tortoise is running slowly...')
        
>>> run_twice(Tortoise()) # 只要是`Animal`类或子类，就会自动调用实际类型的`run()`方法，这就是多态
Tortoise is running slowly...
Tortoise is running slowly...
```

##### “开闭”原则

对扩展开放：允许新增`Animal`子类；

对修改封闭：不需要修改依赖`Animal`类型的`run_twice()`等函数。

##### 静态语言 vs 动态语言

对于静态语言（例如Java）来说，如果需要传入`Animal`类型，则传入的对象必须是`Animal`类型或者它的子类，否则，将无法调用`run()`方法。

对于Python这样的动态语言来说，则不一定需要传入`Animal`类型。我们只需要保证传入的对象有一个`run()`方法就可以了：

```python
class Timer(object):
    def run(self):
        print('Start...')
```

这就是动态语言的“鸭子类型”，它并不要求严格的继承体系，一个对象只要“看起来像鸭子，走起路来像鸭子”，那它就可以被看做是鸭子。

Python的“file-like object“就是一种鸭子类型。对真正的文件对象，它有一个`read()`方法，返回其内容。但是，许多对象，只要有`read()`方法，都被视为“file-like object“。许多函数接收的参数就是“file-like object“，你不一定要传入真正的文件对象，完全可以传入任何实现了`read()`方法的对象。

#### 获取对象信息

##### `type()`

```python
>>> type(123)
<class 'int'>
>>> type('str')
<class 'str'>
>>> type(None)
<type(None) 'NoneType'>
>>> type(abs) # 函数或者类，也可以用`type()`判断
<class 'builtin_function_or_method'>
>>> type(a)
<class '__main__.Animal'>
```

##### `types`

```python
>>> import types
>>> def fn():
...     pass
...
>>> type(fn)==types.FunctionType
True
>>> type(abs)==types.BuiltinFunctionType
True
>>> type(lambda x: x)==types.LambdaType
True
>>> type((x for x in range(10)))==types.GeneratorType
True
```

##### `isinstance()`

能用`type()`判断的基本类型也可以用`isinstance()`判断：：

```
>>> isinstance([1, 2, 3], (list, tuple))
True
>>> isinstance((1, 2, 3), (list, tuple))
True
```

 总是优先使用isinstance()判断类型，可以将指定类型及其子类“一网打尽”。

##### `dir()`

```python
>>> dir('ABC') # 获得一个对象的所有属性和方法，它返回一个包含字符串的list
['__add__', '__class__',..., '__subclasshook__', 'capitalize', 'casefold',..., 'zfill']
```

`getattr()`、`setattr()`以及`hasattr()`

```python
class MyObject(object):
    def __init__(self):
        self.x = 9

    def power(self):
        return self.x * self.x


obj = MyObject()
print(hasattr(obj, 'x'))  # 有属性'x'吗？
print(hasattr(obj, 'y'))  # 有属性'y'吗？
setattr(obj, 'y', 19)     # 设置一个属性'y'
print(getattr(obj, 'y'))  # 获取属性'y'
print(getattr(obj, 'z', 404))  # 获取属性'z'，如果不存在，返回默认值404

print(hasattr(obj, 'power'))   # 有属性'power'吗？
fn = getattr(obj, 'power')     # 获取属性'power'
print(fn())  # 调用fn()与调用obj.power()是一样的
```

##### 小结

只有在不知道对象信息的时候，我们才会去获取对象信息。如果可以直接写：

```
sum = obj.x + obj.y
```

就不要写：

```
sum = getattr(obj, 'x') + getattr(obj, 'y')
```

一个正确的用法的例子如下：

```
def readImage(fp):
    if hasattr(fp, 'read'):
        return readData(fp)
    return None
```

假设我们希望从文件流fp中读取图像，我们首先要判断该fp对象是否存在read方法，如果存在，则该对象是一个流，如果不存在，则无法读取。`hasattr()`就派上了用场。

请注意，在Python这类动态语言中，根据鸭子类型，有`read()`方法，不代表该fp对象就是一个文件流，它也可能是网络流，也可能是内存中的一个字节流，但只要`read()`方法返回的是有效的图像数据，就不影响读取图像的功能。

#### 实例属性

```python
class Student(object):
    gender = 'X'


Bob = Student()
print('Bob.gender属性    :', Bob.gender)
print('Student.gender属性:', Student.gender)

Bob.gender = 'Female'
print('Bob.gender属性    :', Bob.gender)
print('Student.gender属性:', Student.gender)

del Bob.gender
print('Bob.gender属性    :', Bob.gender)
print('Student.gender属性:', Student.gender)
```

```
Bob.gender属性    : X
Student.gender属性: X
Bob.gender属性    : Female
Student.gender属性: X
Bob.gender属性    : X
Student.gender属性: X
```

```python
class Student(object):
    count = 0 # 增加一个类属性(计数)

    def __init__(self, name): # 每创建一个实例，Student.count 加 1
        self.name = name
        Student.count += 1
```

### 面向对象高级编程

#### `__slots__`

```python
def set_score(self, score):
     self.score = score

Student.set_score = set_score # 给class绑定新方法后，所有实例均可调用
```

`__slots__`变量，来限制该class实例能添加的属性：

```python
"""
class ：什么学生
Object：具体的一个学生
"""
class Student(object):
    __slots__ = ('name', 'age')  # 用tuple定义允许绑定的属性名称


s = Student()  # 创建新的实例
s.name = 'Michael'
s.age = 25
s.score = 99  # 绑定不允许的属性'score'
# AttributeError: 'Student' object has no attribute 'score'


class GraduateStudent(Student):
    pass


g = GraduateStudent()
g.score = 9999 # 绑定不允许的属性'score'
# `__slots__`定义的属性仅对当前类实例起作用，对继承的子类是不起作用
```

#### `@property`

```python
class Student(object):

    @property  # 可读属性，相当于 s.get_score()
    def score(self):
        return self._score

    @score.setter  # 可写属性，相当于 s.set_score()
    def score(self, value):
        if not isinstance(value, int):
            raise ValueError('score must be an integer!')
        if value < 0 or value > 100:
            raise ValueError('score must between 0 ~ 100!')
        self._score = value


s = Student()
s.score = 60  # OK，实际转化为s.set_score(60)
s.score       # OK，实际转化为s.get_score()
print(s.score)
```

把一个getter方法变成属性，只需要加上`@property`就可以了，此时，`@property`本身又创建了另一个装饰器`@score.setter`，负责把一个setter方法变成属性赋值，于是，我们就拥有一个可控的属性操作：

```python
class Screen(object):
    @property
    def width(self): # 可读属性
        return _width

    @width.setter
    def width(self, width):  # 可写属性
        self._width = width

    @property
    def height(self): # 可读属性
        return _height

    @height.setter
    def height(self, height):  # 可写属性
        self._height = height

    @property
    def resolution(self):  # 可读属性，因为`resolution`可以根据`width`和`height`计算出来
        return self._height * self._width
```

#### 多重继承 MixIn

```python
class Animal(object):
    pass

# 大类:
class Mammal(Animal):
    pass

class Bird(Animal):
    pass

# 各种动物:
class Dog(Mammal):
    pass

class Ostrich(Bird):
    pass

# 其它属性
class RunnableMixIn(object):
    def run(self):
        print('Running...')

class FlyableMixIn(object):
    def fly(self):
        print('Flying...')

class Dog(Mammal, RunnableMixIn, CarnivorousMixIn): # 多重继承，一个子类就可以同时获得多个父类的所有功能
    pass
class Ostrich(Bird, FlyableMixIn, HerbivoresMixIn):
    pass
```

##### 多进程模式的TCP服务

```
class MyTCPServer(TCPServer, ForkingMixIn):
    pass
```

##### 多线程模式的UDP服务

```
class MyUDPServer(UDPServer, ThreadingMixIn):
    pass
```

##### 协程模型

```
class MyTCPServer(TCPServer, CoroutineMixIn):
    pass
```

#### 定制类

##### __str__

```python
>>> class Student(object):
    def __init__(self, name):
        self.name = name
    def __str__(self):
        return 'Student object (name: %s)' % self.name

>>> s = Student('Michael')
>>> s
<__main__.Student object at 0x00916CB0>

>>> class Student(object):
    def __init__(self, name):
        self.name = name
    def __str__(self):
        return 'Student object (name=%s)' % self.name
    __repr__ = __str__

    
>>> s = Student('Michael')
>>> s
Student object (name=Michael)
```

##### __iter__

```python
class Fib(object):
    def __init__(self):
        self.a, self.b = 0, 1 # 初始化两个计数器a，b

    def __iter__(self):
        return self # 实例本身就是迭代对象，故返回自己

    def __next__(self):
        self.a, self.b = self.b, self.a + self.b # 计算下一个值
        if self.a > 100000: # 退出循环的条件
            raise StopIteration()
        return self.a # 返回下一个值


for n in Fib():
    print(n)
```

##### __getitem__

```python
class Fib(object):
    def __getitem__(self, n): # 要像list那样按照下标取出元素，需要实现`__getitem__()`方法
        a, b = 1, 1
        for x in range(n):
            a, b = b, a + b
        return a

>>> f = Fib()
>>> f[0]
1
>>> f[10]
89
```

但是list有个神奇的切片方法：

```
>>> list(range(100))[5:10]
[5, 6, 7, 8, 9]
```

对于Fib却报错。原因是`__getitem__()`传入的参数可能是一个int，也可能是一个切片对象`slice`，所以要做判断：

```
class Fib(object):
    def __getitem__(self, n):
        if isinstance(n, int): # n是索引
            a, b = 1, 1
            for x in range(n):
                a, b = b, a + b
            return a
        if isinstance(n, slice): # n是切片
            start = n.start
            stop = n.stop
            if start is None:
                start = 0
            a, b = 1, 1
            L = []
            for x in range(stop):
                if x >= start:
                    L.append(a)
                a, b = b, a + b
            return L
```

现在试试Fib的切片：

```
>>> f = Fib()
>>> f[0:5]
[1, 1, 2, 3, 5]
>>> f[:10]
[1, 1, 2, 3, 5, 8, 13, 21, 34, 55]
```

但是没有对step参数作处理：

```
>>> f[:10:2]
[1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89]
```

也没有对负数作处理，所以，要正确实现一个`__getitem__()`还是有很多工作要做的。

此外，如果把对象看成`dict`，`__getitem__()`的参数也可能是一个可以作key的object，例如`str`。

与之对应的是`__setitem__()`方法，把对象视作list或dict来对集合赋值。最后，还有一个`__delitem__()`方法，用于删除某个元素。

总之，通过上面的方法，我们自己定义的类表现得和Python自带的list、tuple、dict没什么区别，这完全归功于动态语言的“”，不需要强制继承某个接口。

##### __getattr__

正常情况下，当我们调用类的方法或属性时，如果不存在，就会报错。若写一个`__getattr__()`方法，动态返回一个属性。修改如下：

```python
class Student(object):

    def __init__(self):
        self.name = 'Michael'

    def __getattr__(self, attr):
        if attr=='score':
            return 99

s = Student()
s.name
# 'Michael'
s.score
# 99
```

```python
class Student(object):

    def __getattr__(self, attr):
        if attr=='age':
            return lambda: 25
```

只是调用方式要变为：

```
>>> s.age()
25
```

注意，只有在没有找到属性的情况下，才调用`__getattr__`，已有的属性，比如`name`，不会在`__getattr__`中查找。

此外，注意到任意调用如`s.abc`都会返回`None`，这是因为我们定义的`__getattr__`默认返回就是`None`。要让class只响应特定的几个属性，我们就要按照约定，抛出`AttributeError`的错误：

```
class Student(object):

    def __getattr__(self, attr):
        if attr=='age':
            return lambda: 25
        raise AttributeError('\'Student\' object has no attribute \'%s\'' % attr)
```

这实际上可以把一个类的所有属性和方法调用全部动态化处理了，不需要任何特殊手段。

这种完全动态调用的特性有什么实际作用呢？作用就是，可以针对完全动态的情况作调用。

举个例子：

现在很多网站都搞REST API，比如新浪微博、豆瓣啥的，调用API的URL类似：

- <http://api.server/user/friends>
- <http://api.server/user/timeline/list>

如果要写SDK，给每个URL对应的API都写一个方法，那得累死，而且，API一旦改动，SDK也要改。

利用完全动态的`__getattr__`，我们可以写出一个链式调用：

```
class Chain(object):

    def __init__(self, path=''):
        self._path = path

    def __getattr__(self, path):
        return Chain('%s/%s' % (self._path, path))

    def __str__(self):
        return self._path

    __repr__ = __str__
```

试试：

```
>>> Chain().status.user.timeline.list
'/status/user/timeline/list'
```

这样，无论API怎么变，SDK都可以根据URL实现完全动态的调用，而且，不随API的增加而改变！

还有些REST API会把参数放到URL中，比如GitHub的API：

```
GET /users/:user/repos
```

调用时，需要把`:user`替换为实际用户名。如果我们能写出这样的链式调用：

```
Chain().users('michael').repos
```

就可以非常方便地调用API了。有兴趣的童鞋可以试试写出来。

##### __call__

```python
class Student(object):
    def __init__(self, name):
        self.name = name

    def __call__(self): # 直接在实例本身上调用
        print('My name is %s.' % self.name)

s = Student('Michael')
s() # self参数不要传入
```

通过`callable()`函数，我们就可以判断一个对象是否是“可调用”对象

```
>>> callable(Student())
True
>>> callable(max)
True
>>> callable([1, 2, 3])
False
>>> callable(None)
False
>>> callable('str')
False
```

本节介绍的是最常用的几个定制方法，还有很多可定制的方法，请参考[Python的官方文档](http://docs.python.org/3/reference/datamodel.html#special-method-names)。

#### 使用枚举类

##### `Enum`类

```python
from enum import Enum

Month = Enum('Month', ('Jan', 'Feb', 'Mar', 'Apr', 'May',
                       'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'))

for name, member in Month.__members__.items():
    print(name, '=>', member, ',', member.value)
```

`value`属性则是自动赋给成员的`int`常量，默认从`1`开始计数。

如果需要更精确地控制枚举类型，可以从`Enum`派生出自定义类：

```python
from enum import Enum, unique


@unique  # `@unique`装饰器可以帮助我们检查保证没有重复值
class Weekday(Enum):
    Sun = 0  # Sun的value被设定为0
    Mon = 1
    Tue = 2
    Wed = 3
    Thu = 4
    Fri = 5
    Sat = 6


for n, m in Weekday.__members__.items():
    print(n, '=>', m)
```

```
Sun => Weekday.Sun
Mon => Weekday.Mon
Tue => Weekday.Tue
Wed => Weekday.Wed
Thu => Weekday.Thu
Fri => Weekday.Fri
Sat => Weekday.Sat
```

可见，既可以用成员名称引用枚举常量，又可以直接根据value的值获得枚举常量。

把`Student`的`gender`属性改造为枚举类型，可以避免使用字符串：

```python
from enum import Enum, unique

@unique
class Gender(Enum):
    male = 0
    female = 1


class Student(object):
    def __init__(self, name, gender):
        self.name = name
        self.gender = gender


Suvan = Student('ChengSuvan', Gender.female)
print(Suvan.gender == Gender.female)
```

#### 使用元类

##### type()

动态语言和静态语言最大的不同，就是函数和类的定义，不是编译时定义的，而是运行时动态创建的。

比方说我们要定义一个`Hello`的class，就写一个`hello.py`模块：

```
class Hello(object):
    def hello(self, name='world'):
        print('Hello, %s.' % name)
```

当Python解释器载入`hello`模块时，就会依次执行该模块的所有语句，执行结果就是动态创建出一个`Hello`的class对象，测试如下：

```
>>> from hello import Hello
>>> h = Hello()
>>> h.hello()
Hello, world.
>>> print(type(Hello))
<class 'type'>
>>> print(type(h))
<class 'hello.Hello'>
```

`type()`函数可以查看一个类型或变量的类型，`Hello`是一个class，它的类型就是`type`，而`h`是一个实例，它的类型就是class `Hello`。

我们说class的定义是运行时动态创建的，而创建class的方法就是使用`type()`函数。

`type()`函数既可以返回一个对象的类型，又可以创建出新的类型，比如，我们可以通过`type()`函数创建出`Hello`类，而无需通过`class Hello(object)...`的定义：

```
>>> def fn(self, name='world'): # 先定义函数
...     print('Hello, %s.' % name)
...
>>> Hello = type('Hello', (object,), dict(hello=fn)) # 创建Hello class
>>> h = Hello()
>>> h.hello()
Hello, world.
>>> print(type(Hello))
<class 'type'>
>>> print(type(h))
<class '__main__.Hello'>
```

要创建一个class对象，`type()`函数依次传入3个参数：

1. class的名称；
2. 继承的父类集合，注意Python支持多重继承，如果只有一个父类，别忘了tuple的单元素写法；
3. class的方法名称与函数绑定，这里我们把函数`fn`绑定到方法名`hello`上。

通过`type()`函数创建的类和直接写class是完全一样的，因为Python解释器遇到class定义时，仅仅是扫描一下class定义的语法，然后调用`type()`函数创建出class。

正常情况下，我们都用`class Xxx...`来定义类，但是，`type()`函数也允许我们动态创建出类来，也就是说，动态语言本身支持运行期动态创建类，这和静态语言有非常大的不同，要在静态语言运行期创建类，必须构造源代码字符串再调用编译器，或者借助一些工具生成字节码实现，本质上都是动态编译，会非常复杂。

### metaclass

除了使用`type()`动态创建类以外，要控制类的创建行为，还可以使用metaclass。

metaclass，直译为元类，简单的解释就是：

当我们定义了类以后，就可以根据这个类创建出实例，所以：先定义类，然后创建实例。

但是如果我们想创建出类呢？那就必须根据metaclass创建出类，所以：先定义metaclass，然后创建类。

连接起来就是：先定义metaclass，就可以创建类，最后创建实例。

所以，metaclass允许你创建类或者修改类。换句话说，你可以把类看成是metaclass创建出来的“实例”。

metaclass是Python面向对象里最难理解，也是最难使用的魔术代码。正常情况下，你不会碰到需要使用metaclass的情况，所以，以下内容看不懂也没关系，因为基本上你不会用到。

我们先看一个简单的例子，这个metaclass可以给我们自定义的MyList增加一个`add`方法：

定义`ListMetaclass`，按照默认习惯，metaclass的类名总是以Metaclass结尾，以便清楚地表示这是一个metaclass：

```
# metaclass是类的模板，所以必须从`type`类型派生：
class ListMetaclass(type):
    def __new__(cls, name, bases, attrs):
        attrs['add'] = lambda self, value: self.append(value)
        return type.__new__(cls, name, bases, attrs)
```

有了ListMetaclass，我们在定义类的时候还要指示使用ListMetaclass来定制类，传入关键字参数`metaclass`：

```
class MyList(list, metaclass=ListMetaclass):
    pass
```

当我们传入关键字参数`metaclass`时，魔术就生效了，它指示Python解释器在创建`MyList`时，要通过`ListMetaclass.__new__()`来创建，在此，我们可以修改类的定义，比如，加上新的方法，然后，返回修改后的定义。

`__new__()`方法接收到的参数依次是：

1. 当前准备创建的类的对象；
2. 类的名字；
3. 类继承的父类集合；
4. 类的方法集合。

测试一下`MyList`是否可以调用`add()`方法：

```
>>> L = MyList()
>>> L.add(1)
>> L
[1]
```

而普通的`list`没有`add()`方法：

```
>>> L2 = list()
>>> L2.add(1)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AttributeError: 'list' object has no attribute 'add'
```

动态修改有什么意义？直接在`MyList`定义中写上`add()`方法不是更简单吗？正常情况下，确实应该直接写，通过metaclass修改纯属变态。

但是，总会遇到需要通过metaclass修改类定义的。ORM就是一个典型的例子。

ORM全称“Object Relational Mapping”，即对象-关系映射，就是把关系数据库的一行映射为一个对象，也就是一个类对应一个表，这样，写代码更简单，不用直接操作SQL语句。

要编写一个ORM框架，所有的类都只能动态定义，因为只有使用者才能根据表的结构定义出对应的类来。

让我们来尝试编写一个ORM框架。

编写底层模块的第一步，就是先把调用接口写出来。比如，使用者如果使用这个ORM框架，想定义一个`User`类来操作对应的数据库表`User`，我们期待他写出这样的代码：

```
class User(Model):
    # 定义类的属性到列的映射：
    id = IntegerField('id')
    name = StringField('username')
    email = StringField('email')
    password = StringField('password')

# 创建一个实例：
u = User(id=12345, name='Michael', email='test@orm.org', password='my-pwd')
# 保存到数据库：
u.save()
```

其中，父类`Model`和属性类型`StringField`、`IntegerField`是由ORM框架提供的，剩下的魔术方法比如`save()`全部由metaclass自动完成。虽然metaclass的编写会比较复杂，但ORM的使用者用起来却异常简单。

现在，我们就按上面的接口来实现该ORM。

首先来定义`Field`类，它负责保存数据库表的字段名和字段类型：

```
class Field(object):

    def __init__(self, name, column_type):
        self.name = name
        self.column_type = column_type

    def __str__(self):
        return '<%s:%s>' % (self.__class__.__name__, self.name)
```

在`Field`的基础上，进一步定义各种类型的`Field`，比如`StringField`，`IntegerField`等等：

```
class StringField(Field):

    def __init__(self, name):
        super(StringField, self).__init__(name, 'varchar(100)')

class IntegerField(Field):

    def __init__(self, name):
        super(IntegerField, self).__init__(name, 'bigint')
```

下一步，就是编写最复杂的`ModelMetaclass`了：

```
class ModelMetaclass(type):

    def __new__(cls, name, bases, attrs):
        if name=='Model':
            return type.__new__(cls, name, bases, attrs)
        print('Found model: %s' % name)
        mappings = dict()
        for k, v in attrs.items():
            if isinstance(v, Field):
                print('Found mapping: %s ==> %s' % (k, v))
                mappings[k] = v
        for k in mappings.keys():
            attrs.pop(k)
        attrs['__mappings__'] = mappings # 保存属性和列的映射关系
        attrs['__table__'] = name # 假设表名和类名一致
        return type.__new__(cls, name, bases, attrs)
```

以及基类`Model`：

```
class Model(dict, metaclass=ModelMetaclass):

    def __init__(self, **kw):
        super(Model, self).__init__(**kw)

    def __getattr__(self, key):
        try:
            return self[key]
        except KeyError:
            raise AttributeError(r"'Model' object has no attribute '%s'" % key)

    def __setattr__(self, key, value):
        self[key] = value

    def save(self):
        fields = []
        params = []
        args = []
        for k, v in self.__mappings__.items():
            fields.append(v.name)
            params.append('?')
            args.append(getattr(self, k, None))
        sql = 'insert into %s (%s) values (%s)' % (self.__table__, ','.join(fields), ','.join(params))
        print('SQL: %s' % sql)
        print('ARGS: %s' % str(args))
```

当用户定义一个`class User(Model)`时，Python解释器首先在当前类`User`的定义中查找`metaclass`，如果没有找到，就继续在父类`Model`中查找`metaclass`，找到了，就使用`Model`中定义的`metaclass`的`ModelMetaclass`来创建`User`类，也就是说，metaclass可以隐式地继承到子类，但子类自己却感觉不到。

在`ModelMetaclass`中，一共做了几件事情：

1. 排除掉对`Model`类的修改；
2. 在当前类（比如`User`）中查找定义的类的所有属性，如果找到一个Field属性，就把它保存到一个`__mappings__`的dict中，同时从类属性中删除该Field属性，否则，容易造成运行时错误（实例的属性会遮盖类的同名属性）；
3. 把表名保存到`__table__`中，这里简化为表名默认为类名。

在`Model`类中，就可以定义各种操作数据库的方法，比如`save()`，`delete()`，`find()`，`update`等等。

我们实现了`save()`方法，把一个实例保存到数据库中。因为有表名，属性到字段的映射和属性值的集合，就可以构造出`INSERT`语句。

编写代码试试：

```
u = User(id=12345, name='Michael', email='test@orm.org', password='my-pwd')
u.save()
```

输出如下：

```
Found model: User
Found mapping: email ==> <StringField:email>
Found mapping: password ==> <StringField:password>
Found mapping: id ==> <IntegerField:uid>
Found mapping: name ==> <StringField:username>
SQL: insert into User (password,email,username,id) values (?,?,?,?)
ARGS: ['my-pwd', 'test@orm.org', 'Michael', 12345]
```

可以看到，`save()`方法已经打印出了可执行的SQL语句，以及参数列表，只需要真正连接到数据库，执行该SQL语句，就可以完成真正的功能。

不到100行代码，我们就通过metaclass实现了一个精简的ORM框架，是不是非常简单？

![真叫人头大](https://cdn.liaoxuefeng.com/cdn/files/attachments/001510832347710ca6c27e2ab8b4885b52bd1914a80e366000/l)

### 小结

metaclass是Python中非常具有魔术性的对象，它可以改变类创建时的行为。这种强大的功能使用起来务必小心。