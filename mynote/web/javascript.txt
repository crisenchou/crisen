JavaScript 由 Brendan Eich 发明。它于 1995 年出现在 Netscape 中（该浏览器已停止更新），并于 1997 年被 ECMA（一个标准协会）采纳。

JavaScript 对大小写敏感 JavaScript以驼峰法命名

JavaScript核心组成
javascript包括三个重要部分：核心（ECMAScript）,文档对象模型（DOM）,浏览器对象模型（BOM）。
JavaScript全局对象
navigator 浏览器对象
     返回当前使用的浏览器的详细情况
screen 屏幕对象
     返回当前用户的屏幕设置
     具体说一下
     width 屏幕宽度（单位是像素）
     height 屏幕高度
     availWidth 屏幕的可用高度
     availHeight 屏幕的可用宽度
     colorDepth   当前颜色所占用的位数
window 对象
     他是JavaScript中最大的对象，它描述的是一个浏览器窗口。一般要引用它的属性和方法时，不需要用“window.xxx”这种形式，而直接使用“xxx”。一个框架页面也是一个窗口
     window弹出框是由windows对象来控制，重写window对象的 alert方法 comfirm方法 prompt方法可以设计个性化弹出框与警告框
     所有的全局变量都是window对象的属性

History历史对象
     back，foward，go
     其中go(x)，x为整数，当为-1时跳转上一个页面，1时跳转后一个页面，等同于back，foward的前进后退红能
Location 地址对象
     地址对象 它描述的是某一个窗口对象所打开的地址
Document文档对象
     open，write，close



方法
indexOf()  返回某个指定的字符串在某个字符串中首次出现的位置
用法  stringObject.indexOf(searchvalue,fromindex)
js中字符串是一个对象  需要通过对象.方法的形式来调用方法  第一个参数是要搜索的字符串 第二个是可选参数 表示开始检索的位置  相当与php中的strpos函数

setInterval()  方法可按照指定的周期（以毫秒计）来调用函数或计算表达式   这个方法十分强大  把代码放到未来执行 可以达到多进程的效果  clearInterval可以关闭该效果  
常用地方 计时器  页面事实刷新  网页聊天等

javascript 需要深刻理解的内容s

1.介绍js的基本数据类型

Undefined、Null、Boolean、Number、String
2.js有哪些内置对象？

数据封装类对象：Object、Array、Boolean、Number 和 String

其他对象：Function、Arguments、Math、Date、RegExp、Error
3.this对象的理解

this总是指向函数的直接调用者（而非间接调用者）；

如果有new关键字，this指向new出来的那个对象；

在事件中，this指向触发这个事件的对象，特殊的是，IE中的attachEvent中的this总是指向全局对象Window；
4.eval是做什么的？

它的功能是把对应的字符串解析成JS代码并运行；

应该避免使用eval，不安全，非常耗性能（2次，一次解析成js语句，一次执行）。

由JSON字符串转换为JSON对象的时候可以用eval，var obj =eval(‘(‘+ str +’)’);
5.DOM怎样添加、移除、移动、复制、创建和查找节点
复制代码

// 创建新节点
createDocumentFragment() //创建一个DOM片段
createElement() //创建一个具体的元素
createTextNode() //创建一个文本节点
// 添加、移除、替换、插入
appendChild()
removeChild()
replaceChild()
insertBefore() //在已有的子节点前插入一个新的子节点
// 查找
getElementsByTagName() //通过标签名称
getElementsByName() //通过元素的Name属性的值(IE容错能力较强，会得到一个数组，其中包括id等于name值的)
getElementById() //通过元素Id，唯一性

复制代码
6.null和undefined的区别？

null是一个表示”无”的对象，转为数值时为0；undefined是一个表示”无”的原始值，转为数值时为NaN。
undefined：

（1）变量被声明了，但没有赋值时，就等于undefined。

（2) 调用函数时，应该提供的参数没有提供，该参数等于undefined。

（3）对象没有赋值的属性，该属性的值为undefined。

（4）函数没有返回值时，默认返回undefined。
null：

（1） 作为函数的参数，表示该函数的参数不是对象。

（2） 作为对象原型链的终点。
7.new操作符具体干了什么呢?

（1）创建一个空对象，并且 this 变量引用该对象，同时还继承了该函数的原型。

（2）属性和方法被加入到 this 引用的对象中。

（3）新创建的对象由 this 所引用，并且最后隐式的返回 this 。
8.JSON 的了解？

JSON(JavaScript Object Notation) 是一种轻量级的数据交换格式。它是基于JavaScript的一个子集。数据格式简单, 易于读写, 占用带宽小。

格式：采用键值对，例如：{‘age’:’12’, ‘name’:’back’}
9.call() 和 apply() 的区别和作用？

apply()函数有两个参数：第一个参数是上下文，第二个参数是参数组成的数组。如果上下文是null，则使用全局对象代替。

如：function.apply(this,[1,2,3]);

call()的第一个参数是上下文，后续是实例传入的参数序列。

如：function.call(this,1,2,3);
10.如何获取UA？

function whatBrowser() { 
     document.Browser.Name.value=navigator.appName; 
     document.Browser.Version.value=navigator.appVersion; 
     document.Browser.Code.value=navigator.appCodeName; 
     document.Browser.Agent.value=navigator.userAgent; 
 }


1. JavaScript 压缩和模块打包

2. 按需加载资源

3. 在使用 DOM 操作库时用上 array-ids

4. 缓存

5. 启用 HTTP/2

6. 应用性能分析

7. 使用负载均衡方案

8. 为了更快的启动时间考虑一下同构

9. 使用索引加速数据库查询

10. 使用更快的转译方案

11. 避免或最小化 JavaScript 和 CSS 的使用而阻塞渲染

12. 用于未来的一个建议：使用 service workers + 流

13. 图片编码优化