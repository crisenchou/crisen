# mysql使用心得

---

使用phpmyadmin的时候 链接远程数据库 出现 Unknown character set: 'utf8mb4' 这样的错误 

原因是因为 utf8mb4是utf8字符集的一个超集(superset),  这个字符集在mysql5.5.3之前是不存在的， 而我的服务器环境的mysql服务器是5.1.73的版本 所以没有这个字符集 进而导致报错

mysql在5.7版本中 提供了对json column的支持

mysql 锁的概念, 在并发性发生的情况下，有可能会导致数据的脏读等现象，为了保证数据的一致性，于是便有了锁的概念
锁分为乐观所和悲观锁

悲观锁(Pessimistic Lock), 每次去拿数据的时候都认为别人会修改，所以每次在拿数据的时候都会上锁，这样别人想拿这个数据就会block直到它拿到锁。传统的关系型数据库里边就用到了很多这种锁机制，比如行锁，表锁等，读锁，写锁等，都是在做操作之前先上锁。

乐观锁(Optimistic Lock), 顾名思义，就是很乐观，每次去拿数据的时候都认为别人不会修改，所以不会上锁，但是在更新的时候会判断一下在此期间别人有没有去更新这个数据，可以使用版本号等机制。乐观锁适用于多读的应用类型，这样可以提高吞吐量，像数据库如果提供类似于write_condition机制的其实都是提供的乐观锁。


锁的粒度主要是行锁和表锁
行锁：在更新数据时，锁住更新的行，不影响其它行
表锁：更新数据时，锁住整个表，对读取数据有较大的影响

mysql有9中存储引擎，分别是FEDERATED,MRG_MYISAM,MYISAN,BLACKHOLE,CSV,MEMORY,ARCHIVE,innoDB,performance_schema.
其中最常用的几种是MYISAN,innoDB,MEMORY,CSV
mysql5.5之前的版本 默认的存储引擎是MYISAM,5.5Z之后的版本则是innoDB
对比MyISAM，innoDB以及MEMORY，
只有innodb支持行锁和事务，另外两种只有表锁，且不支持事务
MySIAM的优点是可以对数据进行压缩，批量插入的速度非常快，但不支持数据缓存，而另外两种存储引擎皆支持数据缓存
innoDB 比另外两种小号的内存都高