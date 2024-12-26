gcc $( pkg-config --cflags gtk4 ) -o main main.c widgets/mb_button.c $( pkg-config --libs gtk4 )
