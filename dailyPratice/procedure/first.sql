BEGIN
	DECLARE ids int;
	CREATE temporary TABLE if not EXISTS temp_dept_ids(id int);
	truncate temp_dept_ids;
	SET ids = (select id from depts where dept_name="TG");
	if ids is not null 
	then
		INSERT into temp_dept_ids values (ids);
		#INSERT into temp_son values (@ids);
		BEGIN
			DECLARE c int;
			DECLARE done int default false;  
			DECLARE cur cursor for select id from depts where parent_id = ids;  
			DECLARE continue HANDLER for not found SET done = true;  
			open cur;  
			parent_loop:loop  
				fetch cur into c;
				if (select count(*) from depts where parent_id=c)>0  then
					BEGIN
						DECLARE son_c int;
						DECLARE son_done int default false;  
						DECLARE son_cur cursor for select id from depts where parent_id = c;
						DECLARE continue HANDLER for not found SET son_done = true;  
						open son_cur;  
						son_loop:loop  
							fetch son_cur into son_c;
							if son_done then  
								leave son_loop;
							else
								insert into temp_dept_ids values (son_c);
							END if;
						END loop;
						close son_cur;
					END;
				end if;
				if done then  
					leave parent_loop;
				else
					insert into temp_dept_ids values (c);
				end if;
			end loop;
			close cur;
		END;

		select user_name from users where dept_id in (select id from temp_dept_ids);
		/*lp:LOOP
			if deep>0 THEN
				insert into temp_dept_ids (select id from temp_son);
				#truncate temp_son;
				
				
				#insert into temp_son (select id from depts where parent_id in (select id from temp_dept_ids));
				SET deep = deep-1;
			else
				leave lp;
			end if;
		end loop;*/
		#select deep;
		/*if (select count(id) from depts where parent_id in (@ids)) is not NULL	
		then 
				INSERT into temp_son (select id from depts where parent_id in (@ids));
		end if;*/
		#select * from temp_dept_ids;
		#insert into temp_dept_ids (select id from temp_son);

		#select id from depts  where parent_id in (select id from temp_dept_ids);
		#INSERT into temp_dept_ids (select id from depts where parent_id in (@ids));
		#select @son=(select id from depts where parent_id in (@ids));
	end if;
	#select * from temp_dept_ids;
	#select user_name from users where dept_id in (select id from temp_dept_ids);
	#select user_name from users where dept_id in (@son);
	#select @ids as ids;
	#select * from users;
END