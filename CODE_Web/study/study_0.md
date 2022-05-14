# JS第一课

## Script标签

`<script>`标签中包裹了 JavaScript 代码，当浏览器遇到 `<script>` 标签，代码会自动运行。

### 外部脚本
    如果你有大量的 JavaScript 代码，我们可以将它放入一个单独的文件。
	脚本文件可以通过 src 特性（attribute）添加到 HTML 文件中。
1、如：`<script src="/path/to/script.js"></script>`这里，/path/to/script.js 是脚本文件从网站根目录开始的绝对路径。当然也可以提供当前页面的相对路径。例如，src ="script.js"，就像 src="./script.js"，表示当前文件夹中的 "script.js" 文件。

2、我们也可以提供一个完整的 URL 地址，例如：
`<script src="https://cdnjs.cloudflare.com/ajax/libs/lodash.js/4.17.11/lodash.js"></script>`

要附加多个脚本，请使用多个标签：
```
<script src="/js/script1.js"></script>
<script src="/js/script2.js"></script>
```

### Tip
一般来说，只有最简单的脚本才嵌入到 HTML 中。更复杂的脚本存放在单独的文件中。使用独立文件的好处是浏览器会下载它，然后将它保存到浏览器的 缓存 中。之后，其他页面想要相同的脚本就会从缓存中获取，而不是下载它。所以文件实际上只会下载一次。这可以节省流量，并使得页面（加载）更快。

一个单独的 `<script>` 标签不能同时有 src 特性和内部包裹的代码。

这将不会工作：
```
<script src="file.js">
  alert(1); // 此内容会被忽略，因为设定了 src
</script>
```

## 代码结构

### 分号与换行符
在大多数情况下，换行意味着一个分号。但是“大多数情况”并不意味着“总是”!大部分时候可以省略分号，但是最好不要省略分号。

### 注释
与C类似使用`//`与`/*...*/`

### 现代模式
使用`"use strict"`指令来激活ES5规范修改之前的旧功能

    请确保`"use strict"`出现在脚本的最顶部，否则严格模式可能无法启用。
	并且程序一旦进入了严格模式，就无法返回默认模式了。

### 变量
使用`let`关键字来声明一个变量

    var 关键字与 let 大体 相同，也用来声明变量，但稍微有些不同，也有点“老派”。

在 JavaScript 中有 8 种基本的数据类型（7 种原始类型和 1 种引用类型）。JS被称为“动态类型”（dynamically typed）的编程语言，意思是虽然编程语言中有不同的数据类型，但是你定义的变量并不会在定义后，被限制为某一数据类型。我们可以将任何类型的值存入变量。例如，一个变量可以在前一刻是个字符串，下一刻就存储一个数字：
```
// 没有错误
let message = "hello";
message = 123456;
```

* Number

number 类型代表整数和浮点数。“number” 类型无法表示大于 (253-1)（即 9007199254740991），或小于 -(253-1) 的整数。

除了常规的数字，还包括所谓的“特殊数值（“specialnumeric values”）”也属于这种类型：Infinity、-Infinity 和 NaN。

    在 JavaScript 中做数学运算是安全的。
	我们可以做任何事：除以 0，将非数字字符串视为数字，等等。

脚本永远不会因为一个致命的错误（“死亡”）而停止。最坏的情况下，我们会得到 NaN 的结果。

* BigInt

BigInt 类型是最近被添加到 JavaScript 语言中的，用于表示任意长度的整数。
```
// 尾部的 "n" 表示这是一个 BigInt 类型
const bigInt=1234567890123456789012345678901234567890n;
```

可以查看 [MDN BigInt 兼容性表](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/BigInt#Browser_compatibility) 来了解哪些版本的浏览器已经支持 BigInt 了。

* String
  
在 JavaScript 中，有三种包含字符串的方式。

1、双引号：`"Hello"`
2、单引号：`'Hello'`
3、反引号：`Hello`
双引号和单引号都是“简单”引用，在 JavaScript 中两者几乎没有什么差别。反引号是 功能扩展 引号。它们允许我们通过将变量和表达式包装在 ${…} 中，来将它们嵌入到字符串中。例如：

```
let name = "John";

// 嵌入一个变量
alert( `Hello, ${name}!` ); // Hello, John!

// 嵌入一个表达式
alert( `the result is ${1 + 2}` ); // the result is 3
```
    ${…} 内的表达式会被计算，计算结果会成为字符串的一部分。可以在 ${…} 内放置任何东西：诸如名为 name 的变量，或者诸如 1 + 2 的算数表达式，或者其他一些更复杂的。

需要注意的是，这仅仅在反引号内有效，其他引号不允许这种嵌入。

* Boolean

boolean 类型仅包含两个值：true 和 false。


* null
  
特殊的 null 值不属于上述任何一种类型。它构成了一个独立的类型，只包含 null 值：

    相比较于其他编程语言，JavaScript 中的 null 不是一个“对不存在的 object 的引用”或者 “null 指针”。

JavaScript 中的 null 仅仅是一个代表“无”、“空”或“值未知”的特殊值。

* undefined

特殊值 undefined 和 null 一样自成类型。
undefined 的含义是 未被赋值。如果一个变量已被声明，但未被赋值，那么它的值就是undefined

* object

用于更复杂的数据结构。

* symbol

用于创建对象的唯一标识符。

* typeof运算符

typeof 运算符返回参数的类型。当我们想要分别处理不同类型值的时候，或者想快速进行数据类型检验时，非常有用。

    1、typeof null 的结果为 "object"。这是官方承认的 typeof 的错误，这个问题来自于 JavaScript 语言的早期阶段，并为了兼容性而保留了下来。null 绝对不是一个 object。null 有自己的类型，它是一个特殊值。typeof 的行为在这里是错误的。

    2、typeof alert 的结果是 "function"，因为 alert 在 JavaScript 语言中是一个函数。我们会在下一章学习函数，那时我们会了解到，在 JavaScript 语言中没有一个特别的 “function” 类型。函数隶属于 object 类型。但是 typeof 会对函数区分对待，并返回 "function"。这也是来自于 JavaScript 语言早期的问题。从技术上讲，这种行为是不正确的，但在实际编程中却非常方便。

### 常量
使用`const`关键字来声明一个常量

    它们不能被修改，如果你尝试修改就会发现报错

