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

Anaconda

可以尝试直接`import numpy`等已安装的第三方模块。

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
bart = Student('Bart Simpson', 59) # 创建实例时就不能传入空的参数
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
setattr(obj, 'y', 19)  # 设置一个属性'y'
print(getattr(obj, 'y'))  # 获取属性'y'
print(getattr(obj, 'z', 404))  # 获取属性'z'，如果不存在，返回默认值404

print(hasattr(obj, 'power'))  # 有属性'power'吗？
fn = getattr(obj, 'power')  # 获取属性'power'
print(fn())  # 调用fn()与调用obj.power()是一样的
```

### 小结

通过内置的一系列函数，我们可以对任意一个Python对象进行剖析，拿到其内部的数据。要注意的是，只有在不知道对象信息的时候，我们才会去获取对象信息。如果可以直接写：

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

### 参考源码