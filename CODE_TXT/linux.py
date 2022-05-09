# 修改主机名
'''
su root
sudo gedit /etc/hostname
sudo gedit /etc/hosts
'''

# 修改root密码
'''
sudo passwd
'''

# 修改用户名
'''
1、修改 /etc/passwd用户信息文件
vim /etc/passwd
2、修改 /etc/shadow用户密码文件
vim /etc/shadow
3、再修改 /etc/group用户组文件
vim /etc/group
4、最后修改用户的家目录
mv /home/admin /home/test
'''

# 切换用户
'''
su [username]
'''

# 添加用户
'''
1、创建用户
创建用户有两条命令：adduser和useradd，对应着两条删除用户的命令：deluser和userdel。
这两种命令之间的区别：
adduser：会自动为创建的用户指定主目录、系统shell版本（有自己的home目录）。
useradd：需要使用参数选项指定上述基本设置，如果不使用任何参数，则创建的用户无密码、无主目录、没有指定shell版本。
'''

# 添加root权限
'''
sudo adduser 新用户名 sudo
'''


# 删除用户
'''
sudo userdel  用户名 不删除相应用户文件夹
sudo userdel -r 用户名 删除用户文件夹
'''

# Windows生成ssh公钥&私钥
'''
ssh-keygen
C:\Users\Administrator\.ssh 文件夹下
id_rsa.pub与id_rsa
'''

# 利用公钥免密ssh登录Linux虚拟机
'''
方法一：
公钥登入（免密登入）
原理：注入公钥到服务端B，表示拥有该公钥的客户端A可以免密登入

将客户端 A 的公钥~/.ssh/id_rsa.pub复制到服务端 B 的授权Key文件~/.ssh/authorized_keys中。可采用手动方式，也可以在客户端 A 执行命令 ssh-copy-id root@172.19.0.2来实现
在客户端 A 执行命令 ssh 172.19.0.2 即可实现免密登入


方法二：
私钥文件登入
原理：客户端A每次登入时携带服务端B的私钥来登入

将服务端 B 的私钥~/.ssh/id_rsa复制到客户端 A 中，假设放在~/.ssh/b_id_rsa，并修改权限为只读。在客户端 A 中执行命令chmod 400 ~/.ssh/b_id_rsa来修改权限
在客户端 A 执行命令 ssh -i ~/.ssh/b_id_rsa root@172.19.0.2 即可实现登入

总结：
公钥：一把钥匙对应多把锁：本机可以登录所有持有本机公钥的服务端
私钥：一把钥匙对应一把锁：本机可以登录本机持有的私钥对应的服务端
'''