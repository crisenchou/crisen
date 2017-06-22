delimiter //
create PROCEDURE getUserByDeptName(in deptName varchar(20))
BEGIN
	CREATE temporary TABLE IF NOT EXISTS temp_dept_ids(id int);
	set @pid = (select id from depts where dept_name=deptName);
	insert into temp_dept_ids values (@pid);
	set max_sp_recursion_depth  = 5;
	call getSonAndInsert(@pid);
	select * from users where dept_id in (select id from temp_dept_ids);
	drop table temp_dept_ids;
END//
 
create PROCEDURE getSonAndInsert(in pid int)
BEGIN
  declare finished int default 0;  
	declare thisCode varchar(200);  
	declare cur cursor for select id from depts where parent_id=pid;  
	declare continue handler for not found set finished = 1;  
	open cur;  
	fetch cur into thisCode;  
	while finished = 0 do  
		set @mySql = CONCAT('insert into temp_dept_ids(id) values("',thisCode,'")');  
		prepare stmt from @mySql;  
		execute stmt;  
		if hasson(thisCode)>0 then  
			call getSonAndInsert(thisCode);  
		end if;
		fetch cur into thisCode;  
	end while;  
	close cur;  
end//
 
create function hasSon(pid int) RETURNS int(11)
BEGIN
    declare finished int default 0;  
    declare count int;  
    declare cur cursor for select count(*) from depts where parent_id = pid;  
    declare continue handler for not found set finished = 1;  
    open cur;  
    fetch cur into count;  
    close cur;  
    if count is null then  
        return 0;  
    else  
        return count;  
    end if;
end//
delimiter 

call getUserByDeptName("TG");