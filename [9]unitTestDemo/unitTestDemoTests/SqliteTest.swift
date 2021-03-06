//
//  SqliteTest.swift
//  unitTestDemoTests
//
//  Created by fangyukui on 2018/3/7.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

import XCTest
@testable import unitTestDemo

class SqliteTest: XCTestCase {
    
    override func setUp() {
        super.setUp()
        // Put setup code here. This method is called before the invocation of each test method in the class.
    }
    
    override func tearDown() {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
        super.tearDown()
    }
    
    func testExample() {
        // This is an example of a functional test case.
        // Use XCTAssert and related functions to verify your tests produce the correct results.
    }
    func testDeal()  {
        let sql1 = "create table  if  not exists t_stu1(myId integer  auto_increment primary key,name text,score real)"
        XCTAssertEqual(SQLiteManager.shareInstance().deal(sql: sql1, uid: "hello"), true)
        
        let sql2 = "insert into t_stu1(name,score) values ('fangyukui',98.0)"
        XCTAssertEqual(SQLiteManager.shareInstance().deal(sql: sql2, uid: "hello"), true)
        
    }
    
    
    
    func testQuery()  {
        let sql = "select * from t_stu1"
        let results = SQLiteManager.shareInstance().querySql(sql: sql, uid: "hello")
        print(results!)
        
    }
    
    
    func testPerformanceExample() {
        // This is an example of a performance test case.
        self.measure {
            // Put the code you want to measure the time of here.
        }
    }
    
}
