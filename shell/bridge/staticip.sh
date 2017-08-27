#!bin/bash

ETC_DIR=/etc/sysconfig/network-scripts
NET_DIR=/etc/sysconfig

ROOT_UID=0

if [ "$UID" -ne "$ROOT_UID" ]  #判断是否为root权限
then
   echo "Must be root to run this script"
   exit 1
fi

cd $ETC_DIR || {
    echo "Cannot change to necessary directory,">&2
    exit 1
}

cat /dev/null  >ifcfg-eth0 && echo "clean ifcfg-eth0 ok!"

#写入eth配置：
cat /home/yangni/staticip/myip >ifcfg-eth0 && echo "write eth0 sucessfully"


cd $NET_DIR || {
    echo "Cannot change to necessary directory,">&2
    exit 1
}

cat /dev/null  >network   #清空network

#将默认网关相关配置写入network
cat /home/yangni/staticip/mynetwork > network && echo "write network sucessfully"

service network restart   #重启网络命令

exit 0
