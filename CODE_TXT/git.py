# 设置/修改用户信息
# git config --global user.name AvaCharon
# git config --global user.name ###@###
# 查看用户信息
# git config --list
# git config --global user.name 
# git config --global user.name 

'''
git status 查看文件状态
git add file 将对应文件的修改添加到暂存区
git add * 将所有文件的修改添加到暂存区
git reset 将暂存区的文件取消暂存或切换到指定版本
git commit 将暂存区的文件修改提交到版本库
git commit -m"message" 将暂存区的文件修改提交到版本库并设置本次提交的备注
git commit -a -m “massage”其他功能如-m参数，加的-a参数可以将所有已跟踪文件中的执行修改或删除操作的文件都提交到本地仓库，即使它们没有经过git add添加到暂存区，注意，新加的文件（即没有被git系统管理的文件）是不能被提交到本地仓库的。建议一般不要使用-a参数，正常的提交还是使用git add先将要改动的文件添加到暂存区，再用git commit 提交到本地版本库。
git log 查看日志

git remote 查看远程仓库
git remote -v 查看远程仓库地址
git remote add name git_url 添加远程仓库
git remote set-url name git_url_new 修改远程仓库
git push origin master 推送到主分支
git clone 从远程仓库克隆
git pull 从远程仓库拉取
git push 推送到远程仓库
'''
# 查看是否连接上
'''
ssh -T git@github.com
Hi AvaCharon! You've successfully authenticated, but GitHub does not provide shell access.
'''
#关于连接不上的问题
#在.ssh文件夹中的config文件中添加以下
'''
Host github.com
  User yjffffz@gmail.com //git中的邮箱
  IgnoreUnknown UseKeychain
  AddKeysToAgent yes
  UseKeychain yes
  IdentityFile "C:\Users\fffz\.ssh\id_rsa"
'''

# OpenSSL SSL_read: Connection was reset, errno 10054
'''
文件过大导致的。
需要修改postBuffer，貌似这玩意叫后置缓存
git config http.postBuffer 524288000

问题应该是与http 的ssl认证有关。
git config --global http.sslVerify "false"
git config lfs.https://github.com/Harris-H/ICPC.git/info/lfs.locksverify false
'''

#Failed to connect to github.com port 443: Timed out
'''
在C:\Windows\System32\drivers\etc\hosts添加

#Github
140.82.113.4 github.com
151.101.185.194 github.global.ssl.fastly.net

在cmd中执行刷新dns设置命令
ipconfig /flushdns
'''




# 建立本地仓库
# git init

# 使用git将项目clone到指定目录
# git clone https://github.com/jquery/jquery.git F:/Github_Fork/

# git branch
# ls -a
# rm -rf .git

'''
1.先fork到自己的GitHub中
2.下载代码到本地：git clone+地址
3.创建并切换分支：

3.1 git status # 查看当前git仓库状态, 确认处于master分支中
3.2 git branch pr-test # 从master分支分出为pr-test的分支
(查看本地有哪些分支：git branch)
(删除分支:git branch -d 分支名)
3.3 git checkout pr-test # 切换至pr-test分支

4.修改文档等
5.上传代码到仓库(add commit push)

5.1 git status # 查看当前做了哪些修改
5.2 git add . # . 表示当前目录 git add . 是把当前目录的所有修改添加到暂存区里(将待传文件放到提交区：git add+文件名) . git add -e +文件名（选择某文件的一部分）
5.3 git status # 确认下修改
5.4 git commit -m ‘this is a commit’ # 输入commit信息, 简要概括下本次修改
(可以查看有有几个远程仓库：git remote -v)
5.5 git log # 查看commit历史(可以不看)
5.6 git push # 提交到自己的远程仓库
（将本次修改更新到仓库：git push private(地址的名字) ）
（git push -u origin master //将本地仓库的东西提交到地址是origin的地址，master分支下）

6.提交pr

6.1 到github自己的仓库主页, 发现会有一个Compare&Pull Request选项, 点击即可填写PR说明.
6.2 PR的标题最好以自己修改的模块文件路径开头, 方便维护者辨识(如本文件是doc/Start:), 然后简要说明下自己为什么做这部分修改, 以及做了什么修改, 达到了怎样的效果.

7.总结
1、将他人的仓库Fork成自己的仓库（访问该仓库页面，点击fork）
2、将自己的仓库clone到本地（git clone 自己仓库的URL）
3、创建特性分支（在GitHub上发送Pull Request时，一般都是发送特性分支。这样一来，Pull Request就拥有了更明确的特性[主题]，让对方了解自己修改代码的意图，有助于提高代码的审查效率）
4、做出自己需要的修改(可以用自己喜欢的编辑器修改)
5、提交修改（git add… & git commit -m “…”）
6、创建远程分支（要从GitHub发送Pull Request，GitHub端的仓库中必须有一个包含了修改后代码的分支。git push origin 远程分支名）
7、发送Pull Request（登陆GitHub，切换到相应分支，点击Compare可查看分支之间的差别。点击New Pull Request，在随后显示的表单中填写本次进行Pull Request的理由，并提交即可）
'''