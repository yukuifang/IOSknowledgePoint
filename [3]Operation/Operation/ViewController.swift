//
//  ViewController.swift
//  Operation
//
//  Created by fangyukui on 2018/3/1.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    fileprivate var operationQueue: OperationQueue!

    override func viewDidLoad() {
        super.viewDidLoad()
//        concurrence()
//        serial_2()
        
//        executionSequence()
        kvo()
        
    }
    //MARK:加入OperationQueue操作队列的操作默认是并发,执行次序是不固定
    func concurrence(){
        let queue = OperationQueue()
        queue.addOperation(BlockOperation(block: {
            print("operation1:" + Thread.current.description)
        }))
        queue.addOperation(BlockOperation(block: {
            print("operation2:" + Thread.current.description)
        }))
        queue.addOperation(BlockOperation(block: {
            print("operation3:" + Thread.current.description)
        }))
    }
    //MARK:加入OperationQueue操作队列的操作默认是并发,当maxConcurrentOperationCount为1的时候，队列的操作是串行，执行次序是固定顺序的，注意：并发和串行 不能决定是不是要开子线程，比如下面的例子执行次序是固定顺序的，但是有两条线程
    func serial_1(){
        let queue = OperationQueue()
        queue.maxConcurrentOperationCount = 1
        queue.addOperation(BlockOperation(block: {
            print("operation1:" + Thread.current.description)
        }))
        queue.addOperation(BlockOperation(block: {
            print("operation2:" + Thread.current.description)
        }))
        queue.addOperation(BlockOperation(block: {
            print("operation3:" + Thread.current.description)
        }))
    }
    //MARK:如果一个operation4封装多个任务，其内部的任务会开启多条线程和当前线程进行执行
    func serial_2(){
        let queue = OperationQueue()
        queue.maxConcurrentOperationCount = 1
        queue.addOperation(BlockOperation(block: {
            print("operation1:" + Thread.current.description)
        }))
        queue.addOperation(BlockOperation(block: {
            print("operation2:" + Thread.current.description)
        }))
        queue.addOperation(BlockOperation(block: {
            print("operation3:" + Thread.current.description)
        }))
        
        
        let operation4 =  BlockOperation(block: {
            print("operation4: task1" + Thread.current.description)
        })
        operation4.addExecutionBlock {
            print("operation4: task2" + Thread.current.description)
        }
        operation4.addExecutionBlock {
            print("operation4: task3" + Thread.current.description)
        }
        queue.addOperation(operation4)
        
        
    }
    
    //MARK:执行顺序
    func executionSequence(){
        let queue1 = OperationQueue()
        let queue2 = OperationQueue()
      
        let ope1 = BlockOperation(block: {
            print("operation1:" + Thread.current.description)
        })
        
        let ope2 = BlockOperation(block: {
            print("operation2:" + Thread.current.description)
        })
        
        let ope3 = BlockOperation(block: {
            print("operation3:" + Thread.current.description)
        })
        
        let ope4 = BlockOperation(block: {
            print("operation4:" + Thread.current.description)
        })
        
        let ope5 = BlockOperation(block: {
            print("operation5:" + Thread.current.description)
        })
        
        let ope6 = BlockOperation(block: {
            print("operation6:" + Thread.current.description)
        })
        
        //注意：不能设置循环依赖，否则两个操作都不能执行;可以跨队列依赖
        ope1.addDependency(ope2)
        ope2.addDependency(ope3)
        ope3.addDependency(ope4)
        ope4.addDependency(ope5)
        ope5.addDependency(ope6)
        
        
        queue1.addOperation(ope1)
        queue1.addOperation(ope2)
        queue1.addOperation(ope3)
        queue1.addOperation(ope4)
        
        queue2.addOperation(ope5)
        queue2.addOperation(ope6)
        
        //结果是
//        operation6:<NSThread: 0x608000461dc0>{number = 3, name = (null)}
//        operation5:<NSThread: 0x60400006a440>{number = 4, name = (null)}
//        operation4:<NSThread: 0x608000461dc0>{number = 3, name = (null)}
//        operation3:<NSThread: 0x60400006a440>{number = 4, name = (null)}
//        operation2:<NSThread: 0x60400006a440>{number = 4, name = (null)}
//        operation1:<NSThread: 0x60400006a440>{number = 4, name = (null)}

        
    }
    
    //MARK:操作提供很多状态可以用KVO来监听的可能
    func kvo() {
        let queue = OperationQueue()
        let oper = BlockOperation(block: {
            print("operation:" + Thread.current.description)
        })
        queue.addOperation(oper)
        
        oper.addObserver(self, forKeyPath:"isCancelled", options: .new, context: nil)
        oper.addObserver(self, forKeyPath:"isFinished", options: .new, context: nil)
        
    }
    override func observeValue(forKeyPath keyPath: String?, of object: Any?, change: [NSKeyValueChangeKey : Any]?, context: UnsafeMutableRawPointer?) {
        print(change ?? "")
    }
    
    
    
    @IBAction func begin(_ sender: Any) {
        operationQueue = OperationQueue()
        operationQueue.maxConcurrentOperationCount = 1
        operationQueue.addOperation(BlockOperation(block: {
            for i in 0..<200000{
               print("operation1:" + "\(i)" + Thread.current.description)
            }
            
        }))
        operationQueue.addOperation(BlockOperation(block: {
            for i in 0..<200000{
                print("operation2:" + "\(i)" + Thread.current.description)
            }
        }))
        operationQueue.addOperation(BlockOperation(block: {
            for i in 0..<200000{
                print("operation3:" + "\(i)" + Thread.current.description)
            }
        }))
        
        
    }
    //只能暂停当前操作后面的操作；当前操作是原子性的，不可分割；操作是有状态的
    @IBAction func pause(_ sender: Any) {
        operationQueue.isSuspended = true
    }
    
    
    @IBAction func resume(_ sender: Any) {
        operationQueue.isSuspended = false
    }
    //只能暂停当前操作后面的操作；当前操作是原子性的，不可分割；操作是有状态的
    @IBAction func cancel(_ sender: Any) {
        operationQueue.cancelAllOperations()
    }
}

