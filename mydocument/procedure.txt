BEGIN
DECLARE n INT;
DECLARE flag int;
DECLARE where_item varchar(255);
DECLARE temp VARCHAR(60);
DECLARE i INT;
#DECLARE statement text;

SET i=1;
SET n=INSTR(params,",");
SET where_item="";
SET temp = SUBSTRING_INDEX(params,",",-1);
SET where_item=concat("where slot",params_count," = ",temp);
WHILE(n>0)
DO
	SET temp = SUBSTRING_INDEX(params,",",1);
	SET params = SUBSTRING(params,n+1);
	SET where_item=concat(where_item," and slot",i," = ", temp);
	SET n=INSTR(params,",");
	SET i=i+1;
END WHILE;

set @statement=CONCAT("select count(*) from absulote_baned  ",where_item,";");

PREPARE statement FROM @statement;
EXECUTE statement;
DEALLOCATE PREPARE statement;
#SELECT SUBSTRING_INDEX(params,",",1);
#SELECT SUBSTRING(params,n+1);
#SELECT SUBSTRING_INDEX(params,",",1);
#select params_count;
#select SUBSTRING_INDEX(params,",",20);
#select SUBSTRING_INDEX(params,",",1);
END



²ÎÊý


IN `params` varchar(255), `params_count` int



select count(*) as count from absulote_baned where slot1='1' or slot2='1' or slot3='1' or slot4='1' or slot5='1' or slot6='1' or slot7='1' or slot8='1' or slot9='1' or slot10='1' or slot11='1' or slot12='1' or slot13='1' or slot14='1' or slot15='1' or slot16='1' or slot17='1' or slot18='1' or slot19='1' or slot20='1' union select count(*) as count from absulote_baned where slot1='2' or slot2='2' or slot3='2' or slot4='2' or slot5='2' or slot6='2' or slot7='2' or slot8='2' or slot9='2' or slot10='2' or slot11='2' or slot12='2' or slot13='2' or slot14='2' or slot15='2' or slot16='2' or slot17='2' or slot18='2' or slot19='2' or slot20='2' union select count(*) as count from absulote_baned where slot1='34' or slot2='34' or slot3='34' or slot4='34' or slot5='34' or slot6='34' or slot7='34' or slot8='34' or slot9='34' or slot10='34' or slot11='34' or slot12='34' or slot13='34' or slot14='34' or slot15='34' or slot16='34' or slot17='34' or slot18='34' or slot19='34' or slot20='34' union select count(*) as count from absulote_baned where slot1='4' or slot2='4' or slot3='4' or slot4='4' or slot5='4' or slot6='4' or slot7='4' or slot8='4' or slot9='4' or slot10='4' or slot11='4' or slot12='4' or slot13='4' or slot14='4' or slot15='4' or slot16='4' or slot17='4' or slot18='4' or slot19='4' or slot20='4' union select count(*) as count from absulote_baned where slot1='54' or slot2='54' or slot3='54' or slot4='54' or slot5='54' or slot6='54' or slot7='54' or slot8='54' or slot9='54' or slot10='54' or slot11='54' or slot12='54' or slot13='54' or slot14='54' or slot15='54' or slot16='54' or slot17='54' or slot18='54' or slot19='54' or slot20='54'


