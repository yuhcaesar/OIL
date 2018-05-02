/*
Navicat MySQL Data Transfer

Source Server         : localhost
Source Server Version : 50714
Source Host           : localhost:3306
Source Database       : monitor

Target Server Type    : MYSQL
Target Server Version : 50714
File Encoding         : 65001

Date: 2018-05-02 15:13:10
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `t_point`
-- ----------------------------
DROP TABLE IF EXISTS `t_point`;
CREATE TABLE `t_point` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `guid` int(11) NOT NULL,
  `producer` varchar(255) DEFAULT NULL,
  `set_date` date DEFAULT NULL,
  `stake_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `FKA0CD92058CD6593E` (`stake_id`),
  CONSTRAINT `FKA0CD92058CD6593E` FOREIGN KEY (`stake_id`) REFERENCES `t_stake` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_point
-- ----------------------------
INSERT INTO `t_point` VALUES ('1', '12', '二位奥多所', '2018-04-19', '9');
