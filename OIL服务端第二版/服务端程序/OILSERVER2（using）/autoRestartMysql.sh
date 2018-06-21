
#!/bin/bash
echo "checking" >> /home/OILSERVER2/log/flash.log
pgrep -x mysqld &> /dev/null
if [ $? -ne 0 ]
then
echo "At time: 'date': MySQL is stop ." >> /home/OILSERVER2/log/flash.log
/etc/init.d/mysqld start
else
echo "MySQL server is running ." >> /home/OILSERVER2/log/flash.log
fi

