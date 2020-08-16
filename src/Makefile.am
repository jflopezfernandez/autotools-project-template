bin_PROGRAMS = project
project_SOURCES = main.c
project_CFLAGS = -std=c17 -Wall -Wextra -Wconversion -fPIE -Wno-unused-parameter -Wformat=2 -Wformat-security -fstack-protector-all -Wstrict-overflow -fsanitize=address -Wmissing-prototypes -Wmissing-declarations -Wstrict-prototypes -Wpointer-arith -Wwrite-strings -Wcast-qual -Wcast-align -Wbad-function-cast -Wformat-security -Wformat-nonliteral -Wmissing-format-attribute -Winline
project_CPPFLAGS = -I$(top_srcdir) -I$(top_srcdir)/include
project_LDFLAGS = -pie -z,noexecstack -z,noexecheap -z,relro -z,now

