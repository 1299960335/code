cc=gcc
bin=proh
file_list=mian.o  proh.o

$(bin):$(file_list)
		$(cc) -o $@ $^
%.o:%.c
		$(cc) -c $<

.PHONY:clean
clean:
		rm -f $(file_list) $(bin)


