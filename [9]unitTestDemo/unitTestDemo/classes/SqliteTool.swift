//
//  SqliteTool.swift
//  unitTestDemo
//
//  Created by fangyukui on 2018/3/7.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

import UIKit
import SQLite3

let kCachePath = NSSearchPathForDirectoriesInDomains(.documentDirectory,.allDomainsMask, true).last!

class SQLiteManager: NSObject {
    //MARK: - 创建类的静态实例变量即为单例对象 let-是线程安全的
    static let instance = SQLiteManager()
    //对外提供创建单例对象的接口
    class func shareInstance() -> SQLiteManager {
        return instance
    }
    
    //定义数据库变量
    var db : OpaquePointer? = nil
    
    func deal(sql:String,uid:String?) -> Bool {
        // 1. 打开数据库
        if !openDB(uid: uid) {
            print("数据库打开失败")
            return false
        }
        print("数据库打开成功")
        // 2. 执行语句
        let sqlP = sql.cString(using: .utf8)
        
        let result = sqlite3_exec(db, sqlP, nil, nil, nil) == SQLITE_OK
        
        // 3. 关闭数据库
        closeDB()
        
        return result;
       
    }
    
    func querySql(sql:String,uid:String?) -> Array<Dictionary<String, Any>>? {
        _ = openDB(uid: uid)
        let sqlP = sql.cString(using: .utf8)
        var ppStmt : OpaquePointer? = nil
        // 1. 创建准备语句
        // 参数1: 一个已经打开的数据库
        // 参数2: 需要中的sql
        // 参数3: 参数2取出多少字节的长度 -1 自动计算 \0
        // 参数4: 准备语句
        // 参数5: 通过参数3, 取出参数2的长度字节之后, 剩下的字符串
        if sqlite3_prepare_v2(db, sqlP, -1, &ppStmt, nil) != SQLITE_OK{
            print("准备语句编译失败")
            return nil
        }
        var results : Array<Dictionary<String,Any>>  = []
        while sqlite3_step(ppStmt) == SQLITE_ROW {
            let rowDic :NSDictionary = [:]
            // 1. 获取所有列的个数
            let columnCount = sqlite3_column_count(ppStmt)
            // 2. 遍历所有的列
            for i in 0 ..< columnCount{
               let columnNamePtr =  sqlite3_column_name(ppStmt, i)
               // 2.1 获取列名
               let columnName = String(cString: columnNamePtr!)
                
                // 2.2 获取列值
                // 不同列的类型, 使用不同的函数, 进行获取
                // 2.2.1 获取列的类型
               let type = sqlite3_column_type(ppStmt, i)
                // 2.2.2 根据列的类型, 使用不同的函数, 进行获取
                var value : Any?
                switch (type) {
                case SQLITE_INSERT:
                    value = sqlite3_column_int(ppStmt, i)
                    break
                case SQLITE_FLOAT:
                    value = sqlite3_column_double(ppStmt, i)
                case SQLITE_BLOB:
                    value = sqlite3_column_blob(ppStmt, i)
                case SQLITE_NULL:
                    value = "";
                case SQLITE3_TEXT:
                    value = String(cString: sqlite3_column_text(ppStmt, i) )
                    
                default:
                    break
                }
                rowDic.setValue(value, forKey: columnName)
                results.append(rowDic as! Dictionary<String, Any>)
                
                
                
                
            }
            
        }
        // 5. 释放资源
        sqlite3_finalize(ppStmt);
        
        closeDB()
        
        return results
        
    }
    
    

    
    
    fileprivate func openDB(uid:String?)->Bool{
        var dbName = (kCachePath as NSString).appendingPathComponent("common.db")
        if  let i_uid = uid,i_uid.count > 0  {
           dbName = (kCachePath as NSString).appendingPathComponent("\(i_uid).db")
        }
        let cDBName = dbName.cString(using: .utf8)
        
        return sqlite3_open(cDBName, &db) == SQLITE_OK
        
    }
    fileprivate func closeDB(){
        sqlite3_close(db)
    }
    
    
}
