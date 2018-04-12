/*
SQLyog 企业版 - MySQL GUI v8.14 
MySQL - 5.0.96-community-nt : Database - oil
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
CREATE DATABASE /*!32312 IF NOT EXISTS*/`oil` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `oil`;

/*Table structure for table `oildatademo` */

DROP TABLE IF EXISTS `oildatademo`;

CREATE TABLE `oildatademo` (
  `DataID` int(20) NOT NULL auto_increment,
  `Data1` char(20) collate utf8_unicode_ci default NULL COMMENT 'Data1',
  `Data2` char(20) collate utf8_unicode_ci NOT NULL COMMENT 'Data2',
  `data3` char(20) collate utf8_unicode_ci NOT NULL COMMENT 'Data3',
  `Data4` char(20) collate utf8_unicode_ci NOT NULL COMMENT 'Data4',
  `Data5` char(20) collate utf8_unicode_ci NOT NULL COMMENT 'Data5',
  `Data6` char(20) collate utf8_unicode_ci NOT NULL COMMENT 'Data6',
  `Data7` char(20) collate utf8_unicode_ci default NULL COMMENT 'Data7',
  `Data8` char(20) collate utf8_unicode_ci default NULL COMMENT 'Data8',
  `time` char(40) collate utf8_unicode_ci default NULL,
  PRIMARY KEY  (`DataID`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

/*Data for the table `oildatademo` */

insert  into `oildatademo`(`DataID`,`Data1`,`Data2`,`data3`,`Data4`,`Data5`,`Data6`,`Data7`,`Data8`,`time`) values (1,'0.002344','0.00646','42','24','23','23','43','43','2018/1/19 10:25:36'),(2,'0.709054','0.00765','43','23','23','3','47','75','2018/1/19 10:25:37'),(3,'0.89021','0.00867','34','432','2','34','534','324','2018/1/19 10:25:38'),(4,'0.000654','0.00654','65','56','56','54','423','64','2018/1/19 10:25:39'),(5,'0.867532','0.00765','32','32','32','54','43','43','2018/1/19 10:25:40'),(7,'0.86533','54','32','12','2','21','423','65','2018/1/19 10:25:41'),(8,'42','23','32','54','48','21','65','98','2018/1/19 10:25:42'),(9,'4','432','43','43','43','43','43','43','2018/1/19 10:25:43'),(10,'6','432','432','432','432','432','432','432','2018/1/19 10:25:44'),(11,'7','54','543','543','543','543','543','543','2018/1/19 10:25:45');

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
