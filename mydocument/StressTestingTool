apache ab

进入到apache所在的安装目录的bin目录下  执行ab.exe命令开启压力测试工具

ab命令的一些参数的说明
ab -n5000 -c200 url  
Options are:
    -n requests     Number of requests to perform 参数表示需要请求的次数 
    -c concurrency  Number of multiple requests to make at a time 表示并发量 
    -t timelimit    Seconds to max. to spend on benchmarking  最大请求时间 访问n次请求的最大限制时间
                    This implies -n 50000 
    -s timeout      Seconds to max. wait for each response 每次请求等待时间间隔 
                    Default is 30 seconds 初始时间为30秒
    -b windowsize   Size of TCP send/receive buffer, in bytes  最大传输字节
    -B address      Address to bind to when making outgoing connections   绑定输出地址
    -p postfile     File containing data to POST. Remember also to set -T  需要传输的post数据
    -u putfile      File containing data to PUT. Remember also to set -T  需要传输的put数据
    -T content-type Content-type header to use for POST/PUT data, eg. 设置头部类型
                    'application/x-www-form-urlencoded'
                    Default is 'text/plain'
    -v verbosity    How much troubleshooting info to print   
    -w              Print out results in HTML tables
    -i              Use HEAD instead of GET
    -x attributes   String to insert as table attributes
    -y attributes   String to insert as tr attributes
    -z attributes   String to insert as td or th attributes
    -C attribute    Add cookie, eg. 'Apache=1234'. (repeatable)
    -H attribute    Add Arbitrary header line, eg. 'Accept-Encoding: gzip'
                    Inserted after all normal header lines. (repeatable)
    -A attribute    Add Basic WWW Authentication, the attributes
                    are a colon separated username and password.
    -P attribute    Add Basic Proxy Authentication, the attributes
                    are a colon separated username and password.
    -X proxy:port   Proxyserver and port number to use
    -V              Print version number and exit
    -k              Use HTTP KeepAlive feature
    -d              Do not show percentiles served table.
    -S              Do not show confidence estimators and warnings.
    -q              Do not show progress when doing more than 150 requests
    -l              Accept variable document length (use this for dynamic pages)

    -g filename     Output collected data to gnuplot format file.
    -e filename     Output CSV file with percentages served
    -r              Don't exit on socket receive errors.
    -m method       Method name
    -h              Display usage information (this message)


siege  linux命令行下 执行wget 或者是 yum apt-get等命令下载源码  然后执行./configure 以及make命令安装siege

siege -c100 -r100 url   


-c 200 指定并发数200
-r 5 指定测试的次数5
-f urls.txt 制定url的文件
-i internet系统，随机发送url
-b 请求无需等待 delay=0
-t 5 持续测试5分钟
-H   指定头部类型

输出结果
Transactions: 总共测试次数
Availability: 成功次数百分比
Elapsed time: 总共耗时多少秒
Data transferred: 总共数据传输
Response time: 等到响应耗时
Transaction rate: 平均每秒处理请求数
Throughput: 吞吐率
Concurrency: 最高并发
Successful transactions: 成功的请求数
Failed transactions: 失败的请求数