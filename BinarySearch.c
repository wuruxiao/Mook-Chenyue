Position BinarySearch( List L, ElementType X ){
    Position head = 1;
    Position tail = L->Last;

    while (head <= tail)
    {
        Position medium = head + (tail - head) / 2;

        if(X == L->Data[medium])    return medium;

        if(X < L->Data[medium]){
            tail = medium - 1;
        }else{
            head = medium + 1;
        }
        
    }

    return NotFound;  
}