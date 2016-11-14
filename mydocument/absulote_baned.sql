/*
Navicat MySQL Data Transfer

Source Server         : fuck04
Source Server Version : 50714
Source Host           : 10.0.0.4:3306
Source Database       : PT_AntiCheat

Target Server Type    : MYSQL
Target Server Version : 50714
File Encoding         : 65001

Date: 2016-11-14 18:28:11
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for absulote_baned
-- ----------------------------
DROP TABLE IF EXISTS `absulote_baned`;
CREATE TABLE `absulote_baned` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `enable` tinyint(1) NOT NULL DEFAULT '1',
  `slot1` varchar(40) CHARACTER SET utf8mb4 DEFAULT NULL,
  `slot2` varchar(40) CHARACTER SET utf8mb4 DEFAULT NULL,
  `slot3` varchar(40) CHARACTER SET utf8mb4 DEFAULT NULL,
  `slot4` varchar(40) CHARACTER SET utf8mb4 DEFAULT NULL,
  `slot5` varchar(40) CHARACTER SET utf8mb4 DEFAULT NULL,
  `slot6` varchar(40) CHARACTER SET utf8mb4 DEFAULT NULL,
  `slot7` varchar(40) CHARACTER SET utf8mb4 DEFAULT NULL,
  `slot8` varchar(40) CHARACTER SET utf8mb4 DEFAULT NULL,
  `slot9` varchar(40) CHARACTER SET utf8mb4 DEFAULT NULL,
  `slot10` varchar(40) CHARACTER SET utf8mb4 DEFAULT NULL,
  `slot11` varchar(40) CHARACTER SET utf8mb4 DEFAULT NULL,
  `slot12` varchar(40) CHARACTER SET utf8mb4 DEFAULT NULL,
  `slot13` varchar(40) CHARACTER SET utf8mb4 DEFAULT NULL,
  `slot14` varchar(40) CHARACTER SET utf8mb4 DEFAULT NULL,
  `slot15` varchar(40) CHARACTER SET utf8mb4 DEFAULT NULL,
  `slot16` varchar(40) CHARACTER SET utf8mb4 DEFAULT NULL,
  `slot17` varchar(40) CHARACTER SET utf8mb4 DEFAULT NULL,
  `slot18` varchar(40) CHARACTER SET utf8mb4 DEFAULT NULL,
  `slot19` varchar(40) CHARACTER SET utf8mb4 DEFAULT NULL,
  `slot20` varchar(40) CHARACTER SET utf8mb4 DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `slot1` (`slot1`),
  KEY `slot2` (`slot2`),
  KEY `slot3` (`slot3`),
  KEY `slot4` (`slot4`),
  KEY `slot5` (`slot5`),
  KEY `slot6` (`slot6`),
  KEY `slot7` (`slot7`),
  KEY `slot8` (`slot8`),
  KEY `slot9` (`slot9`),
  KEY `slot10` (`slot10`),
  KEY `slot11` (`slot11`),
  KEY `slot12` (`slot12`),
  KEY `slot13` (`slot13`),
  KEY `slot14` (`slot14`),
  KEY `slot15` (`slot15`),
  KEY `slot16` (`slot16`),
  KEY `slot17` (`slot17`),
  KEY `slot18` (`slot18`),
  KEY `slot19` (`slot19`),
  KEY `slot20` (`slot20`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Records of absulote_baned
-- ----------------------------
