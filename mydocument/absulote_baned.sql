/*
Navicat MySQL Data Transfer

Source Server         : fuck04
Source Server Version : 50714
Source Host           : 10.0.0.4:3306
Source Database       : PT_AntiCheat

Target Server Type    : MYSQL
Target Server Version : 50714
File Encoding         : 65001

Date: 2016-11-14 18:03:51
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for absulote_baned
-- ----------------------------
DROP TABLE IF EXISTS `absulote_baned`;
CREATE TABLE `absulote_baned` (
  `macaddress_05` varchar(255) DEFAULT NULL,
  `macaddress_04` varchar(255) DEFAULT NULL,
  `macaddress_03` varchar(255) DEFAULT NULL,
  `macaddress_02` varchar(255) DEFAULT NULL,
  `macaddress_01` varchar(255) DEFAULT NULL,
  `harddisk_serial_05` varchar(255) DEFAULT NULL,
  `harddisk_serial_04` varchar(255) DEFAULT NULL,
  `harddisk_serial_03` varchar(255) DEFAULT NULL,
  `harddisk_serial_02` varchar(255) DEFAULT NULL,
  `harddisk_serial_01` varchar(40) DEFAULT NULL,
  `motherboard_serial` varchar(40) DEFAULT NULL,
  `motherboard_type` varchar(20) DEFAULT NULL,
  `cpu_id` varchar(40) DEFAULT NULL,
  `bios_id` varchar(40) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- ----------------------------
-- Records of absulote_baned
-- ----------------------------
