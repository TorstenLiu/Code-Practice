#define _CRT_SECURE_NO_WARNINGS 1

/* 哈希算法：
负载因子=哈希表中元素/表格容量

哈希冲突：不同的元素通过哈希函数计算出相同的哈希地址，导致多个元素要插同一位置引起冲突
	 解决方法：
		 1.设计一个合理哈希函数(直接定值法和除留余数法)但是不能从根本上解决。
		 2.闭散列：从发生哈希冲突的位置开始，找下一个空位置
		   (1) 线性探测：从当前位置依次往后找
			   优点：处理哈希冲突方式比较简单
			   缺点：一旦发生冲突，容易造成数据的堆积
			   解决：不挨着往后找空位置，避免产生数据堆积--->非线性探测里的二次探测
			   扩容：负载因子=70%
		 (2)非线性探测
			 二次探测：从当前位置，不采用依次往后查找  H(i)=H(0)+i^2，H(i+1)=H(0)+(i+1)^2，相减：H(i+1)=H(i)+2*i+1
			   末尾：%表容量，保证每次是不同的位置；不能置0，会引起无休止的探测
			   优点：可以解决线性探测中数据堆积的问题
			   缺点：如果表格中的空位置比较少，容易错过空位置，可能就需要探测多次
			   扩容：负载因子>=60%
		 3.开散列
		 采用哈希桶 (1)计算当前元素所在桶号
			   (2)在桶号对应链表查看看桶号位置是否有元素，无则直接插入，有则往下遍历该桶号对应链表，直到找到空位置
			   (3)插入元素

函数实现;
(1)闭散列：hashtable.h 
 1.插入：
   a.通过哈希函数计算元素在哈希表中的位置
   b.如果当前位置状态不为empty：
	  (1)如果状态为exist，且当前位置数值与插入元素数值相同，直接返回
	  (2)如果状态为delete或为exist且data不同，则线性探测或者二次探测，直到找到empty的位置为止
   c.插入元素
 2.查找：
   a.通过哈希函数计算元素在哈希表中的位置
   b.如果当前状态不为empty：
	   (1)如果状态为exist且元素相同，返回当前下标
	   (2)如果状态为delete或者为exist且data不同，则线性探测或者二次探测，直到找到empty的位置为止

3.删除：
  a.通过哈希函数计算元素在哈希表中的位置
  b.判断当前位置是否=被删除元素
	   是---删除
	   不是---继续向后探测

问题：
1.当元素是非int类型时，无法进行哈希函数计算---封装一个转换方法
2.除留余数法，怎么找素数---利用素数表
3.如何扩容---负载因子>=0.7时扩容，重新创建一个哈希表，将旧表中状态为EXSIT的元素向新哈希表中进行插入


(2)开散列：hashbucket.h
把哈希地址相同(发生哈希冲突)的元素放在同一个链表中
1.插入：
  (1)通过哈希函数计算当前桶号
  (2)检测值为data的元素是否存在
    a.如果有，返回
    b.如果没有，插入新节点,头插

2.删除（删除值为data的第一个元素）
(1)通过哈希函数计算当前桶号
(2)在桶号所在链表中寻找值为data的节点
    a.如果找到，删除
    b.找不到，继续往后找，直到末尾

3.查找
(1)通过哈希函数计算当前桶号
(2)在桶号所在链表中寻找值为data的节点
    a.如果找到，返回
    b.找不到，继续往后找，直到末尾

问题：
1.什么时候扩容
2.怎么扩容
3.改造哈希表封装unordered系列关联式容器 map和set
*/

//#include "hashtable.h"
#include "hashbucket.h"
int main()
{
	/*TestHashTable1();
	TestHashTable2();*/
	TestHashBucket();
	system("pause");
	return 0;
}
