# A Simple Implementation of Vector with C array

## Initialise a vector struct
```c
Vector vec;
initialise(&vec);
```

## Insert
```c
printf("insert 99 at index 0\n");
insert(&vec, 0, 99);
print(&vec);
int m_size = max_size(&vec);
int sz = size(&vec);
printf("max size: %d\n", m_size);
printf("vector size: %d\n" ,sz);
```
```
insert 99 at index 0
[ 99 ]
max size: 10
vector size: 1
```

## Erase
```c
erase(&vec, 0);
print(&vec);
m_size = max_size(&vec);
sz = size(&vec);
printf("max size: %d\n", m_size);
printf("vector size: %d\n" ,sz);
```
```
erase val at index 0
[ ]
max size: 10
vector size: 0
```

## Push Back
```c
int i;
for(i = 0; i < 20; i++) {
    printf("push %d\n", i);
    push_back(&vec, i);
    print(&vec);
}
m_size = max_size(&vec);
sz = size(&vec);
printf("max size: %d\n", m_size);
printf("vector size: %d\n" ,sz);
```
```
push 0
[ 0 ]
push 1
[ 0 1 ]
push 2
[ 0 1 2 ]
push 3
[ 0 1 2 3 ]
push 4
[ 0 1 2 3 4 ]
push 5
[ 0 1 2 3 4 5 ]
push 6
[ 0 1 2 3 4 5 6 ]
push 7
[ 0 1 2 3 4 5 6 7 ]
push 8
[ 0 1 2 3 4 5 6 7 8 ]
push 9
[ 0 1 2 3 4 5 6 7 8 9 ]
push 10
[ 0 1 2 3 4 5 6 7 8 9 10 ]
push 11
[ 0 1 2 3 4 5 6 7 8 9 10 11 ]
push 12
[ 0 1 2 3 4 5 6 7 8 9 10 11 12 ]
push 13
[ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 ]
push 14
[ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 ]
push 15
[ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 ]
push 16
[ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 ]
push 17
[ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 ]
push 18
[ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 ]
push 19
[ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 ]
max size: 20
vector size: 20
```

## Pop Back
```c
for(i = 0; i < 10; i++) {
    printf("pop\n");
    pop_back(&vec);
    print(&vec);
}
m_size = max_size(&vec);
sz = size(&vec);
```
```
pop
[ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 ]
pop
[ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 ]
pop
[ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 ]
pop
[ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 ]
pop
[ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 ]
pop
[ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 ]
pop
[ 0 1 2 3 4 5 6 7 8 9 10 11 12 ]
pop
[ 0 1 2 3 4 5 6 7 8 9 10 11 ]
pop
[ 0 1 2 3 4 5 6 7 8 9 10 ]
pop
[ 0 1 2 3 4 5 6 7 8 9 ]
max size: 20
vector size: 10
```

## Get First Value
```c
int front = get_front(&vec);
printf("front: %d\n", front);
```
```
front: 0
```

## Get Last Value
```c
int back = get_back(&vec);
printf("back: %d\n", back);
```
```
back: 9
```

## Get Value at Index
```c
int get_3 = get(&vec, 3);
int get_exceed = get(&vec, sz);
printf("get value at index 3: %d\n", get_3);
printf("get value at index %d: %d\n", sz, get_exceed);
```
```
get value at index 3: 3
get value at index 10: -1
```

## Resize
```c
printf("resize to 50\n");
resize(&vec, 50);
m_size = max_size(&vec);
sz = size(&vec);
printf("max size: %d\n", m_size);
printf("vector size: %d\n" ,sz);
printf("resize to 1\n");
resize(&vec, 1);
m_size = max_size(&vec);
sz = size(&vec);
printf("max size: %d\n", m_size);
printf("vector size: %d\n" ,sz);
```
```
resize to 50
max size: 50
vector size: 10
resize to 1
max size: 50
vector size: 10
```

## Shrink to Fit
```c
printf("shrink to fit\n");
shrink_to_fit(&vec);
m_size = max_size(&vec);
sz = size(&vec);
printf("max size: %d\n", m_size);
printf("vector size: %d\n" ,sz);
print(&vec);
```
```
shrink to fit
max size: 10
vector size: 10
[ 0 1 2 3 4 5 6 7 8 9 ]
```
