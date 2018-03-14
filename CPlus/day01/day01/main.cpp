//
//  main.cpp
//  day01
//
//  Created by fangyukui on 2018/3/13.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!" << endl;
//    char buf[10];
    
//    scanf("%s",buf);
    
//    fgets(buf, 10, stdin);
    
//    cin >> buf;
    
//    cin.getline(buf, 10);
    
//    string buf;
//    cin>>buf;
//    cout << buf << endl;
    
    int k[] = {2, 4, 6, 8, 10, 12};
    int *p = k;
    printf("%d\n", *p++);
    printf("%d\n", (*p)++);
    printf("%d\n", *++p);
    printf("%d\n", ++*p);

    
    

    
    
    return 0;
}
