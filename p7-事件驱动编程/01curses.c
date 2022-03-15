nt main()
{
    char	message[] = "Hello";
    char	blank[]   = "     ";
    int	dir = +1;
    int	pos = LEFTEDGE ;

    initscr();
    clear();
    while(1){
        move(ROW,pos);
        addstr( message );		/* draw string		*/
        move(LINES-1,COLS-1);		/* park the cursor	*/   // 将光标隐藏起来
        refresh();			/* show string		*/
        sleep(1);
        move(ROW,pos);			/* erase string		*/
        addstr( blank );
        pos += dir;			/* advance position	*/
        if ( pos >= RIGHTEDGE )		/* check for bounce	*/
            dir = -1;
        if ( pos <= LEFTEDGE )
            dir = +1;
    }
}