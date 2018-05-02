/**
 * Created by solly on 2015/6/11.
 */
//防冲突写法
jQuery.noConflict();

(function($) {

    $(function(){
        var timer = null;
        var TIME = 300;
        //首页banner部分，鼠标hover切换效果
        $(".banner_nav_wrap").find(".banner_nav_a").hover(function(){
            var that = this;
            clearTimeout(timer);
            timer = setTimeout(function(){
                bannerNavAHover(that);
            },TIME);
        },function(){
            clearTimeout(timer);
            timer = setTimeout(function(){
                bannerNavALeave();
            },1000);
        });
        /*如果鼠标在内容上，则不自动跳转到今日关注*/
        $(".banner_content_box").hover(function(){
            clearTimeout(timer);
        },function(){
            clearTimeout(timer);
            timer = setTimeout(function(){
                bannerNavALeave();
            },1000);
        });

        //大话主席-bannerjs
        $(".slideBox").slide({mainCell:".bd ul",autoPlay:true,effect:"leftLoop",delayTime:700,interTime: 5000});

        $(".loop_ldhd").slide({mainCell:".loop_ldhd_cont .loop_ldhd_list",autoPlay:true,vis:7,effect:"leftMarquee",interTime:50,trigger:"click"});
        //$(".loop_ldhd").find(".tempWrap").width(688);
		//$(".loop_ldhd_list").find("li").css("width","auto");

        //今日关注部分的新闻列表切换效果
        $(".news_sort").find(".news_sort_a").hover(function(){
            var that = this;
            clearTimeout(timer);
            timer = setTimeout(function(){
                newsSortAHover(that);
            },TIME);
        },function(){
            clearTimeout(timer);
        });
        $(".news_list").find(".news_list_ul").hide().eq(0).show();//初始显示第一项

        //政务公开部分切换效果
        $(".gongkai_title").find("a").not(".xzqlqd").not(".yfxz").hover(function(){
            var that = this;
            clearTimeout(timer);
            timer = setTimeout(function(){gongkaiTitleAHover(that);},TIME);
        },function(){
            clearTimeout(timer);
        });
        $(".gongkai_list_wrap").find(".gongkai_list").eq(0).show();

        //办事服务切换
        $(".banshi_title").find("a").hover(function(){
            var that = this;
            clearTimeout(timer);
            timer = setTimeout(function(){banshiTitleAHover(that);},TIME)
        },function(){
            clearTimeout(timer);
        });
        $(".banshi_list_wrap").find(".banshi_list").eq(0).show();

    });


    /**
     * 首页banner部分，鼠标hover处理程序
     */
    function bannerNavAHover(that){
        var $this = $(that);
        var index = $this.index();

        //切换当前选中的banner_nav_a
        $this.addClass("active").siblings().removeClass("active");

        //显示对应的banner_content_box
        //$(".banner_cont_wrap").find(".banner_content_box").hide().eq(index).fadeIn();
        $(".banner_cont_wrap").find(".banner_cont_wrap_inner").animate({"top":-(index*327)});
    }

    /**
     * 鼠标移出时，1秒后，回复到今日关注
     */
    function bannerNavALeave(){
        var $bannerNavA = $(".banner_nav_wrap").find(".banner_nav_a");
        if($bannerNavA.eq(0).hasClass("active")){return;}
        $bannerNavA.removeClass("active").eq(0).addClass("active");
        $(".banner_cont_wrap").find(".banner_cont_wrap_inner").animate({"top":0});
    }

    /**
     * 首页banner新闻列表部分，鼠标hover处理程序
     */
    function newsSortAHover(that){
        var $this = $(that);
        var index = $this.index();

        //切换当前选中的banner_nav_a
        $this.addClass("active").siblings().removeClass("active");

        //显示对应的news_list_ul
        $(".news_list").find(".news_list_ul").hide().eq(index).show();

        //移动指示条到指定位置
        scrollCursorTo(index);
    }

    /**
     * 移动指示条到指定位置
     * @param index
     */
    function scrollCursorTo(index){
        var $newsSortA = $(".news_sort").find(".news_sort_a").eq(index);
        var left = $newsSortA[0].offsetLeft;
        var width = $newsSortA.outerWidth(true);

        $(".news_sort").find(".news_sort_cursor").animate({"left":left, "width":width},"fast");
    }

    /**
     * 公开部分鼠标hover切换效果
     * @param that
     */
    function gongkaiTitleAHover(that){
        var $this = $(that);
        var index = $this.index();

        //切换当前选中的a
        $this.addClass("active").siblings().removeClass("active");

        //显示对应的信息列表
        $(".gongkai_list_wrap").find(".gongkai_list").hide().eq(index).show();
    }

    //办事服务
    function banshiTitleAHover(that){
        var $this = $(that);
        var index = $this.index();

        $this.addClass("active").siblings().removeClass("active");
        $("#banshi_list_wrap").find(".banshi_list").hide().eq(index).show();
    }

})(jQuery);