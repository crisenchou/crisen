JavaScript �� Brendan Eich ���������� 1995 ������� Netscape �У����������ֹͣ���£������� 1997 �걻 ECMA��һ����׼Э�ᣩ���ɡ�

JavaScript �Դ�Сд���� JavaScript���շ巨����

JavaScript�������
javascript����������Ҫ���֣����ģ�ECMAScript��,�ĵ�����ģ�ͣ�DOM��,���������ģ�ͣ�BOM����
JavaScriptȫ�ֶ���
navigator ���������
     ���ص�ǰʹ�õ����������ϸ���
screen ��Ļ����
     ���ص�ǰ�û�����Ļ����
     ����˵һ��
     width ��Ļ��ȣ���λ�����أ�
     height ��Ļ�߶�
     availWidth ��Ļ�Ŀ��ø߶�
     availHeight ��Ļ�Ŀ��ÿ��
     colorDepth   ��ǰ��ɫ��ռ�õ�λ��
window ����
     ����JavaScript�����Ķ�������������һ����������ڡ�һ��Ҫ�����������Ժͷ���ʱ������Ҫ�á�window.xxx��������ʽ����ֱ��ʹ�á�xxx����һ�����ҳ��Ҳ��һ������
     window����������windows���������ƣ���дwindow����� alert���� comfirm���� prompt����������Ƹ��Ի��������뾯���
     ���е�ȫ�ֱ�������window���������

History��ʷ����
     back��foward��go
     ����go(x)��xΪ��������Ϊ-1ʱ��ת��һ��ҳ�棬1ʱ��ת��һ��ҳ�棬��ͬ��back��foward��ǰ�����˺���
Location ��ַ����
     ��ַ���� ����������ĳһ�����ڶ������򿪵ĵ�ַ
Document�ĵ�����
     open��write��close



����
indexOf()  ����ĳ��ָ�����ַ�����ĳ���ַ������״γ��ֵ�λ��
�÷�  stringObject.indexOf(searchvalue,fromindex)
js���ַ�����һ������  ��Ҫͨ������.��������ʽ�����÷���  ��һ��������Ҫ�������ַ��� �ڶ����ǿ�ѡ���� ��ʾ��ʼ������λ��  �൱��php�е�strpos����

setInterval()  �����ɰ���ָ�������ڣ��Ժ���ƣ������ú����������ʽ   �������ʮ��ǿ��  �Ѵ���ŵ�δ��ִ�� ���Դﵽ����̵�Ч��  clearInterval���Թرո�Ч��  
���õط� ��ʱ��  ҳ����ʵˢ��  ��ҳ�����

javascript ��Ҫ�����������s

1.����js�Ļ�����������

Undefined��Null��Boolean��Number��String
2.js����Щ���ö���

���ݷ�װ�����Object��Array��Boolean��Number �� String

��������Function��Arguments��Math��Date��RegExp��Error
3.this��������

this����ָ������ֱ�ӵ����ߣ����Ǽ�ӵ����ߣ���

�����new�ؼ��֣�thisָ��new�������Ǹ�����

���¼��У�thisָ�򴥷�����¼��Ķ���������ǣ�IE�е�attachEvent�е�this����ָ��ȫ�ֶ���Window��
4.eval����ʲô�ģ�

���Ĺ����ǰѶ�Ӧ���ַ���������JS���벢���У�

Ӧ�ñ���ʹ��eval������ȫ���ǳ������ܣ�2�Σ�һ�ν�����js��䣬һ��ִ�У���

��JSON�ַ���ת��ΪJSON�����ʱ�������eval��var obj =eval(��(��+ str +��)��);
5.DOM������ӡ��Ƴ����ƶ������ơ������Ͳ��ҽڵ�
���ƴ���

// �����½ڵ�
createDocumentFragment() //����һ��DOMƬ��
createElement() //����һ�������Ԫ��
createTextNode() //����һ���ı��ڵ�
// ��ӡ��Ƴ����滻������
appendChild()
removeChild()
replaceChild()
insertBefore() //�����е��ӽڵ�ǰ����һ���µ��ӽڵ�
// ����
getElementsByTagName() //ͨ����ǩ����
getElementsByName() //ͨ��Ԫ�ص�Name���Ե�ֵ(IE�ݴ�������ǿ����õ�һ�����飬���а���id����nameֵ��)
getElementById() //ͨ��Ԫ��Id��Ψһ��

���ƴ���
6.null��undefined������

null��һ����ʾ���ޡ��Ķ���תΪ��ֵʱΪ0��undefined��һ����ʾ���ޡ���ԭʼֵ��תΪ��ֵʱΪNaN��
undefined��

��1�������������ˣ���û�и�ֵʱ���͵���undefined��

��2) ���ú���ʱ��Ӧ���ṩ�Ĳ���û���ṩ���ò�������undefined��

��3������û�и�ֵ�����ԣ������Ե�ֵΪundefined��

��4������û�з���ֵʱ��Ĭ�Ϸ���undefined��
null��

��1�� ��Ϊ�����Ĳ�������ʾ�ú����Ĳ������Ƕ���

��2�� ��Ϊ����ԭ�������յ㡣
7.new�������������ʲô��?

��1������һ���ն��󣬲��� this �������øö���ͬʱ���̳��˸ú�����ԭ�͡�

��2�����Ժͷ��������뵽 this ���õĶ����С�

��3���´����Ķ����� this �����ã����������ʽ�ķ��� this ��
8.JSON ���˽⣿

JSON(JavaScript Object Notation) ��һ�������������ݽ�����ʽ�����ǻ���JavaScript��һ���Ӽ������ݸ�ʽ��, ���ڶ�д, ռ�ô���С��

��ʽ�����ü�ֵ�ԣ����磺{��age��:��12��, ��name��:��back��}
9.call() �� apply() ����������ã�

apply()������������������һ�������������ģ��ڶ��������ǲ�����ɵ����顣�����������null����ʹ��ȫ�ֶ�����档

�磺function.apply(this,[1,2,3]);

call()�ĵ�һ�������������ģ�������ʵ������Ĳ������С�

�磺function.call(this,1,2,3);
10.��λ�ȡUA��

function whatBrowser() { 
     document.Browser.Name.value=navigator.appName; 
     document.Browser.Version.value=navigator.appVersion; 
     document.Browser.Code.value=navigator.appCodeName; 
     document.Browser.Agent.value=navigator.userAgent; 
 }


1. JavaScript ѹ����ģ����

2. ���������Դ

3. ��ʹ�� DOM ������ʱ���� array-ids

4. ����

5. ���� HTTP/2

6. Ӧ�����ܷ���

7. ʹ�ø��ؾ��ⷽ��

8. Ϊ�˸��������ʱ�俼��һ��ͬ��

9. ʹ�������������ݿ��ѯ

10. ʹ�ø����ת�뷽��

11. �������С�� JavaScript �� CSS ��ʹ�ö�������Ⱦ

12. ����δ����һ�����飺ʹ�� service workers + ��

13. ͼƬ�����Ż�