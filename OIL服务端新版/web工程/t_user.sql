/*
Navicat MySQL Data Transfer

Source Server         : localhost
Source Server Version : 50714
Source Host           : localhost:3306
Source Database       : monitor

Target Server Type    : MYSQL
Target Server Version : 50714
File Encoding         : 65001

Date: 2018-05-02 15:13:25
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `t_user`
-- ----------------------------
DROP TABLE IF EXISTS `t_user`;
CREATE TABLE `t_user` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nickname` varchar(255) DEFAULT NULL,
  `password` varchar(255) DEFAULT NULL,
  `type` int(11) NOT NULL,
  `username` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_user
-- ----------------------------
INSERT INTO `t_user` VALUES ('1', '管理员', '202cb962ac59075b964b07152d234b70', '1', 'admin');
INSERT INTO `t_user` VALUES ('4', '李四', '202cb962ac59075b964b07152d234b70', '0', 'lisi');
INSERT INTO `t_user` VALUES ('5', '王五', '202cb962ac59075b964b07152d234b70', '0', 'wangwu');
INSERT INTO `t_user` VALUES ('6', '张四', '202cb962ac59075b964b07152d234b70', '0', 'zhangsan');
