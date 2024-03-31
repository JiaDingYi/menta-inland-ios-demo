//
//  DemoMUNativeTableViewCell.m
//  MentaSDKExample
//
//  Created by iMacMe on 2024/1/10.
//

#import "DemoMUNativeTableViewCell.h"
#import "DemoNormalModel.h"
#define BUD_RGB(r,g,b) [UIColor colorWithRed:(r/255.0) green:(g/255.0) blue:(b/255.0) alpha:1]
#define GlobleHeight (self.contentView.frame.size.height)
#define GlobleWidth (self.contentView.frame.size.width)
#define imgBgColor BUD_RGB(0xf0, 0xf0, 0xf0)
#define edge 15
@interface DemoMUNativeTableViewCell ()
@property (nonatomic, strong, nullable) UIView *separatorLine;
@property (nonatomic, strong, nullable) UILabel *titleLabel;
@property (nonatomic, strong, nullable) UILabel *inconLable;
@property (nonatomic, strong, nullable) UILabel *sourceLable;
@property (nonatomic, strong, nullable) UIImageView *closeIncon;
@property (nonatomic, strong, nullable) UIImageView *img;

@end

@implementation DemoMUNativeTableViewCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        self.selectionStyle = UITableViewCellSelectionStyleNone;
        [self buildupView];
    }
    return self;
}

- (void)buildupView {
    _separatorLine = [[UIView alloc] initWithFrame:CGRectMake(edge, 0, GlobleWidth-edge*2, 0.5)];
    _separatorLine.backgroundColor = BUD_RGB(0xd9, 0xd9, 0xd9);
    [self.contentView addSubview:_separatorLine];
    
    _titleLabel = [UILabel new];
    _titleLabel.numberOfLines = 2;
    _titleLabel.font = [UIFont systemFontOfSize:18];
    _titleLabel.textColor = [UIColor blackColor];
    [self.contentView addSubview:_titleLabel];
    
    _sourceLable = [[UILabel alloc] init];
    _sourceLable.font = [UIFont systemFontOfSize:12];
    _sourceLable.textColor = [UIColor blackColor];
    [self.contentView addSubview:_sourceLable];
    
    _inconLable = [[UILabel alloc] init];
    _inconLable.font = [UIFont systemFontOfSize:10];
    _inconLable.textColor = [UIColor redColor];
    _inconLable.textAlignment = NSTextAlignmentCenter;
    _inconLable.clipsToBounds = YES;
    _inconLable.layer.cornerRadius = 3;
    _inconLable.layer.borderWidth = 0.5;
    _inconLable.layer.borderColor = [UIColor redColor].CGColor;
    [self.contentView addSubview:_inconLable];
    
    _closeIncon = [[UIImageView alloc] init];
    [_closeIncon setImage:[UIImage imageNamed:@"feedClose.png"]];
    [self.contentView addSubview:_closeIncon];
    
    _img = [[UIImageView alloc] init];
    _img.backgroundColor = imgBgColor;
    [self.contentView addSubview:_img];

}

- (void)setModel:(DemoNormalModel *)model {
    _model = model;
    _titleLabel.attributedText = [self titleAttributeText:model.title];
    _sourceLable.attributedText = [self subtitleAttributeText:model.source];
    _inconLable.text = model.incon;

    

}

- (void)layoutSubviews {
    [super layoutSubviews];
    self.separatorLine.frame = CGRectMake(edge, 0, GlobleWidth-edge*2, 0.5);
    self.closeIncon.frame = CGRectMake(GlobleWidth - 10 - edge,GlobleHeight - 10 - edge, 10, 10);
    
    _titleLabel.frame = CGRectMake(edge, edge, GlobleWidth-edge*2, 50);
    _inconLable.frame = CGRectMake(edge, self.model.cellHeight - 12 - edge, 27, 14);
    if (self.model.incon && self.model.incon.length!=0) {
        _inconLable.hidden = NO;
        _sourceLable.frame = CGRectMake(self.inconLable.frame.origin.x+self.inconLable.frame.size.width + edge, self.inconLable.frame.origin.y+1, 200, 12);
    }else{
        _inconLable.hidden = YES;
        _sourceLable.frame = CGRectMake(edge, self.inconLable.frame.origin.y, 200, 12);
    }
    _closeIncon.frame = CGRectMake(GlobleWidth - 10 - edge, self.model.cellHeight - 10 - edge, 10, 10);


}

- (NSAttributedString *)titleAttributeText:(NSString *)text {
    if (text == nil) {
        return nil;
    }
    NSMutableDictionary *attribute = @{}.mutableCopy;
    NSMutableParagraphStyle * titleStrStyle = [[NSMutableParagraphStyle alloc] init];
    titleStrStyle.lineSpacing = 5;
    titleStrStyle.alignment = NSTextAlignmentJustified;
    attribute[NSFontAttributeName] = [UIFont systemFontOfSize:17.f];
    attribute[NSParagraphStyleAttributeName] = titleStrStyle;
    return [[NSAttributedString alloc] initWithString:text attributes:attribute];
}

- (NSAttributedString *)subtitleAttributeText:(NSString *)text {
    if (text == nil) {
        return nil;
    }
    NSMutableDictionary *attribute = @{}.mutableCopy;
    attribute[NSFontAttributeName] = [UIFont systemFontOfSize:12.f];
    attribute[NSForegroundColorAttributeName] = [UIColor lightGrayColor];
    return [[NSAttributedString alloc] initWithString:text attributes:attribute];
}

@end
