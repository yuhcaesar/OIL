/*
Navicat MySQL Data Transfer

Source Server         : localhost
Source Server Version : 50714
Source Host           : localhost:3306
Source Database       : monitor

Target Server Type    : MYSQL
Target Server Version : 50714
File Encoding         : 65001

Date: 2018-05-02 15:13:20
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `t_stake`
-- ----------------------------
DROP TABLE IF EXISTS `t_stake`;
CREATE TABLE `t_stake` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `mark` varchar(255) DEFAULT NULL,
  `mileage` varchar(255) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `pline_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `FKA0F9FFEFC8D4C134` (`pline_id`),
  CONSTRAINT `FKA0F9FFEFC8D4C134` FOREIGN KEY (`pline_id`) REFERENCES `t_pline` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_stake
-- ----------------------------
INSERT INTO `t_stake` VALUES ('9', '80E,70W', '山河大坝', 'A级测试桩', '2');
INSERT INTO `t_stake` VALUES ('10', 'sasas', 'sasas', 'aaa', '3');
