//
//  modelToolTest.swift
//  unitTestDemoTests
//
//  Created by fangyukui on 2018/3/13.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

import XCTest

@testable import unitTestDemo

class modelToolTest: XCTestCase {
        
    override func setUp() {
        super.setUp()
        
        // Put setup code here. This method is called before the invocation of each test method in the class.
        
        // In UI tests it is usually best to stop immediately when a failure occurs.
       

        // In UI tests it’s important to set the initial state - such as interface orientation - required for your tests before they run. The setUp method is a good place to do this.
    }
    
    override func tearDown() {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
        super.tearDown()
    }
    
    func testExample() {
        // Use recording to get started writing UI tests.
        // Use XCTAssert and related functions to verify your tests produce the correct results.
    }
    
    func testModelTool()  {
        let dic =   ModelTool.classIvarNameTypeDic(cls: StudentModel.self)
        print(dic)
        
    }
    
}
