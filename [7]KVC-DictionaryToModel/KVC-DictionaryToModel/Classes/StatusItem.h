
//  KVC-DictionaryToModel
//
//  Created by fangyukui on 2018/3/2.
//  Copyright © 2018年 fangyukui. All rights reserved.
//

#import <Foundation/Foundation.h>

// 设计模型有哪些属性 => 字典
// KVC:模型中属性必须与字典中key一一对应
@class User;
@interface StatusItem : NSObject

// 自动生成属性 => 根据字典
@property (nonatomic, strong) NSString *source;

@property (nonatomic, assign) NSInteger reposts_count;

@property (nonatomic, strong) NSArray *pic_urls;

@property (nonatomic, strong) NSString *created_at;

@property (nonatomic, assign) NSInteger attitudes_count;

@property (nonatomic, strong) NSString *idstr;

@property (nonatomic, strong) NSString *text;

@property (nonatomic, assign) NSInteger comments_count;

@property (nonatomic, strong) User *user;

+ (instancetype)itemWithDict:(NSDictionary *)dict;

@end
