/*
Navicat MySQL Data Transfer

Source Server         : localhost
Source Server Version : 50714
Source Host           : localhost:3306
Source Database       : monitor

Target Server Type    : MYSQL
Target Server Version : 50714
File Encoding         : 65001

Date: 2018-05-02 15:13:04
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `t_pline`
-- ----------------------------
DROP TABLE IF EXISTS `t_pline`;
CREATE TABLE `t_pline` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `length` int(11) NOT NULL,
  `name` varchar(255) DEFAULT NULL,
  `com_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `FKA0CC34D9F35121DA` (`com_id`),
  CONSTRAINT `FKA0CC34D9F35121DA` FOREIGN KEY (`com_id`) REFERENCES `t_com` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_pline
-- ----------------------------
INSERT INTO `t_pline` VALUES ('1', '5000', '抚顺管道', '1');
INSERT INTO `t_pline` VALUES ('2', '3600', '鞍山管线', '2');
INSERT INTO `t_pline` VALUES ('3', '6300', '丹东管线', '6');
INSERT INTO `t_pline` VALUES ('4', '3600', 'AAA', '5');
