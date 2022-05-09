/*僵尸毁灭工程Linux云服务器搭建（个人留档）

参考：
https://note.youdao.com/ynoteshare1/index.html?id=fe65179d613ebedb058b2754006ef718&type=note
https://www.osradar.com/install-steamcmd-ubuntu/


//*******************************************************
//可能会缺失环境包，保险起见进入根目录以及安装对应的环境包
{
cd /
yum install glibc.i686
yum install libstdc++.i686
yum install gcc
}
*********************************************************/


//安装steamcmd
cd /usr/local/
mkdir steamcmd
cd steamcmd/ 

//下载steamcmd 安装包
wget https://steamcdn-a.akamaihd.net/client/installer/steamcmd_linux.tar.gz
tar -zxvf steamcmd_linux.tar.gz
 
//启动steamcmd
cd /usr/local/steamcmd
./steamcmd.sh 


//******************************************************************
//若无法正常运行，可能是系统更新不完全或缺失依赖包（我使用Ubantu20.04时遇到该问题）
{
//更新
sudo apt update
sudo apt upgrade

//取权限
sudo -i
adduser steam

//安装一个名为lib32gcc1的SteamCMD的依赖包
apt-get install lib32gcc1
su -ls /bin/bash steam

//重试
wget https://steamcdn-a.akamaihd.net/client/installer/steamcmd_linux.tar.gz
tar xvf steamcmd_linux.tar.gz
./steamcmd.sh
}
***********************************************************************/
 

//启动之后登陆(account 换成你的steam账号，password换成你对应的密码 或者用匿名账号anonymous 亦可) 
login account password //或login anonymous  

//如果显示获取用户信息失败，则需要更新内核
yum update kernel
shutdow -r now //这一步是更新内核后重启

//登陆完成之后设置你的游戏下载路径(我这里设置的是/usr/local/games/project目录下)
force_install_dir /usr/local/games/project
 
//设置完成之后下载僵尸毁灭工程服务器
app_update 380870 validate
 
//下载完成之后退出
quit

 

//设置swap分区(避免学生机内存不足直接把进程杀掉)
//查看是否有swap分区
free -m

//如果显示出来的swap 后面是0 0 0 则需要设置swap分区(我这里设置的是8g 即8192)
dd if=/dev/zero of=/var/swap bs=1M count=8192
//设置权限
chmod 600 /var/swap
//创建swap分区
mkswap /var/swap
//启用swap
swapon /var/swap
//设置开机自动设置swap
echo '/var/swap   swap   swap   default 0 0' >> /etc/fstab
 
//最后再用free -m 查看swap分区是否有值，如果有值则设置成功
free -m
 



Tips：

//可先在本地打开游戏新建服务器，将服务器配置好，再将本地的配置文件（C:/users/你的用户名/Zomboid/Server里的三个文件）上传到服务器的/root/Zomboid/Servers中
避免繁琐指令操作



//需要更新测试服务器或mod怎么办?
//首先需要停止你的服务器运行，在服务器指令窗口按ctrl+z即可

cd /root/steamcmd
./steamcmd.sh
force_install_dir /root/pzServer
login anonymous
app_update 380870 -beta b41multiplayer validate
quit
//最后再重新进入server-start.sh所在的/root/pzServer文件夹按照之前的服务器启动步骤再来一遍即可。
cd /root/pzServer
cd /usr/local/games/project
bash start-server.sh





//***********************************************************************************
                                    其他问题
************************************************************************************/




//************************************************************************
Question1: 如果在开服的时候报错GLIBCXX3.4.21 not found，可能是gcc版本过低，请按下面的步骤安装

//安装工具
yum groupinstall "Development Tools"

//下载所需的包
cd /usr/local
//这一步如果无法下载，可以直接用电脑下下来传到linux主机上
wget http://ftp.tsukuba.wide.ad.jp/software/gcc/releases/gcc-5.4.0/gcc-5.4.0.tar.bz2
tar -xvf gcc-5.4.0.tar.bz2
cd gcc-5.4.0
./contrib/download_prerequisites
mkdir build
cd build
../configure --enable-checking=release --enable-languages=c,c++ --disable-multilib
make && make install

//error: C++ preprocessor "/lib/cpp" fails sanity check 的问题输入下两行
yum install glibc-headers
yum install gcc-c++
 
cp /usr/local/lib64/libstdc++.so.6.0.21 /lib64
cd /lib64
rm -rf libstdc++.so.6
ln -s libstdc++.so.6.0.21 libstdc++.so.6




//************************************************************************
Question2:关于/lib64/libstdc++.so.6: version `CXXABI_1.3.8’ not found
//可能是libstdc++.so.6 版本过低导致的
//看看自己的 libstdc++.so.6 里是否包含了 CXXABI_1.3.8
# strings /usr/lib64/libstdc++.so.6 | grep CXXABI

//注意，不一定是GCC版本过低，我们要升级 libstdc++.so.6 ，顺便升级GCC。如果只升级GCC（通过scl）是无效的，因为gcc的版本高了，但是他的libstdc++是 require的 原来的 libstdc++.so.6。
//解决方法：重新编译GCC。

sudo yum install gmp-devel mpfr-devel libmpc-devel -y
cd download
wget ftp://ftp.gnu.org/gnu/gcc/gcc-9.2.0/gcc-9.2.0.tar.xz
xz -d gcc-9.2.0.tar.xz
tar -xf gcc-9.2.0.tar
cd gcc-9.2.0
./configure --disable-multilib --enable-languages=c,c++ --prefix=$HOME/local
make -j
make -j install

//安装完毕后，将新安装的路径加入到环境变量里。
export LD_LIBRARY_PATH=$HOME/local/lib64





//************************************************************************
Question3:关于ipv6 

//如果你的是阿里云服务器可能需要打开ipv6地址请求(使用vim的时候一定要慎重，至于vim怎么修改保存自行百度)
vim /etc/modprobe.d/disable_ipv6.conf
 
//这是修改以前的文件
alias net-pf-10 off
alias ipv6 off
options ipv6 disable=1
 
//修改成这样
alias net-pf-10 off
#alias ipv6 off
options ipv6 disable=0
 
//然后修改network，将ipv6打开(依旧是vim修改)
vim /etc/sysconfig/network
 
//修改前(这里需要注意，如果你没有这么多行这种代码你就不用自行加上，你只需要将ipv6=no改成yes就好)
NETWORKING=yes
HOSTNAME=coolnull
NETWORKING_IPV6=no
PEERNTP=no
GATEWAY=*.*.*.*
 
//修改后
NETWORKING=yes
HOSTNAME=coolnull
NETWORKING_IPV6=yes
PEERNTP=no
GATEWAY=*.*.*.*
 
//再修改sysctl.conf，将这几项修改成0(如果没有这几项则自己添加上就行)
vim /etc/sysctl.conf
 
//修改前
net.ipv6.conf.all.disable_ipv6 = 1
net.ipv6.conf.default.disable_ipv6 = 1
net.ipv6.conf.lo.disable_ipv6 = 1
 
//修改后
net.ipv6.conf.all.disable_ipv6 = 0
net.ipv6.conf.default.disable_ipv6 = 0
net.ipv6.conf.lo.disable_ipv6 = 0
 
//设置好以后重启服务器测试看是否支持ipv6(输入后能看到有输出则设置成功)
ifconfig|grep -i inet6