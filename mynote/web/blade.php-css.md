marquee标签  可以让元素进行自滚动效果

sup标签设置上标   sub标签设置下标

margin: 0 auto; 可以实现元素居中

aside 标签定义 article以外的内容

a标签的href使用mailto  会调用计算机的outlook发送邮件
<a href="mailto:someone@example.com?Subject=Hello%20again" target="_top">

overflow 属性  当元素发生溢出时应该做的事情

opacity 属性设置元素的透明度  默认为1 不透明

vertical-align属性用于设置元素垂直对齐方式

keygen标签 可以对表单的字段进行加密   加密之后私钥存储在本地  公钥发送到服务器

在响应页面使用header可以实现前端跨域
header('Access-Control-Allow-Origin:*');  *表示允许所有url的跨域
header('Access-Control-Allow-Methods:POST');
header('Access-Control-Allow-Headers:x-requested-with,content-type');

jsonp跨域的弱点是  所有的提交都是post形式 是非官方的跨域操作  使用header可以使用post跨域