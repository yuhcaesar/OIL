//替换空格
String.prototype.trim = function(){  
	return this.replace(/[ ]/g,"");   
}  
$(function(){
	//导航菜单
	var ind = 4;
	var nav= jQuery(".nav");
	var init = jQuery(".nav .m").eq(ind);
	var block = jQuery(".nav .block"); 
	block.css({"left":init.position().left-3}); 
	nav.hover(function(){},function(){ block.animate({"left":init.position().left-3},100); }); 

	jQuery(".nav").slide({ 
		type:"menu", 
		titCell:".m", 
		targetCell:".sub", 
		delayTime:300, 
		triggerTime:0, 
		returnDefault:true,
		defaultIndex:ind,
		startFun:function(i,c,s,tit){ 
			block.animate({"left":tit.eq(i).position().left-3},100);
		}
	});
	
	//banner
	jQuery(".full_banner").slide({
		 titCell:".hd ul", 
		 mainCell:".bd ul", 
		 effect:"fold",  
		 autoPlay:true, 
		 autoPage:true,
		 trigger:"click",
		 interTime:3500
	});	
	
	//notice scroll
	jQuery(".notice_box").slide({mainCell:"#notice_scroll",effect:"topLoop", autoPlay:true,interTime:3500});
	
	
	//聚焦文本框
	$('.input_focus').focusout(function() {
		var _this_val = $(this).val().trim();
		if(_this_val == ''){
			$(this).val('请输入关键字...');
		}
	});
	
	//添加回车识别事件
	$(document).keydown(function(e){
		var e = window.event||e;
		if(e.keyCode == 13){
			//搜索框数据提交
			search_data_submit();
		}	
	})
	
	//在线客服
	var kefu_list = $('.kefu_list');
	$('.kefu_icon').click(function(){
		var _this = $(this);
		_this.removeClass('kefu_icon_hide');
		_this.removeClass('kefu_icon_show');
		if(kefu_list.is(':visible')){
			_this.animate({'right':0},100);
			kefu_list.animate({'right':-134},100,function(){
				$(this).hide(0);	
				_this.addClass('kefu_icon_hide');
			});
		}else{
			_this.addClass('kefu_icon_show');
			_this.animate({'right':134},100);
			kefu_list.show(0).animate({'right':0},100);
		}
	});
	$('.kefu_list a').click(function(){
		$('.kefu_icon').removeClass('kefu_icon_hide');
		$('.kefu_icon').removeClass('kefu_icon_show');	
		kefu_list.hide(0);
		$('.kefu_icon').css('right',0);
	});
});
//聚焦文本框
function focus_input(this_obj,default_str){
	var _this = $(this_obj);
	var _this_val = _this.val();
	if(_this_val == default_str){
		_this.val('');
		return false;
	}
}
//搜索框数据提交
function search_data_submit(){
	var seach_str = $('#seach_text').val().trim();
	if(seach_str.length < 1){
		return false;
	}
	$('#search_form_data').submit();
}