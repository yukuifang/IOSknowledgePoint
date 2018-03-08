//
//  Calculate.swift
//  unitTestDemo
//
//  Created by fangyukui on 2018/3/7.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

import UIKit

class Calculate: NSObject {
    class func add(a:Int,b:Int) -> Int {
        return a + b
    }
    class func divide(a:Int,b:Int) -> Int {
        if b == 0{
            return 0
        }
        return a / b
    }
}
