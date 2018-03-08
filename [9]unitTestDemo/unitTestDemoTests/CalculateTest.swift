//
//  CalculateTest.swift
//  unitTestDemoTests
//
//  Created by fangyukui on 2018/3/7.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

import XCTest
@testable import unitTestDemo
class CalculateTest: XCTestCase {
    
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
    func testCalcu()  {
        let addResult  = Calculate.add(a: 1, b: 2)
        XCTAssertEqual(addResult, 3)
        
        let divResult1 = Calculate.divide(a: 2, b: 5)
        XCTAssertEqual(divResult1, 0)
        
        let divResult2 = Calculate.divide(a: 2, b: 0)
        XCTAssertEqual(divResult2, 0)
        
        
    }
    
    
    func testPerformanceExample() {
        // This is an example of a performance test case.
        self.measure {
            // Put the code you want to measure the time of here.
        }
    }
    
}
