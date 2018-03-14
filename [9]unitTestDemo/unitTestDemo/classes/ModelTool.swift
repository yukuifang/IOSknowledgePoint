//
//  ModelTool.swift
//  unitTestDemo
//
//  Created by fangyukui on 2018/3/13.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

import UIKit


@objc class ModelTool: NSObject {
    class func tableName(cls:AnyClass)->String {
        return NSStringFromClass(cls)
    }
    class func classIvarNameTypeDic(cls:AnyClass)->Dictionary<String, Any> {
        var count:UInt32 = 0
        var nameTypeDic:Dictionary<String,Any> = [:]
        let ivars = class_copyIvarList(cls, &count)
        for i in 0..<count{
            if let ivar = ivars?[Int(i)]{
                let name = String(cString: ivar_getName(ivar)!)
                let ivarType = NSString.init(cString: ivar_getTypeEncoding(ivar)!, encoding: String.Encoding.utf8.rawValue)
                let type = String(cString: ivar_getTypeEncoding(ivar)!, encoding: .utf8)
                nameTypeDic[name] = type
                
            }
        }
        return nameTypeDic
    }

}
