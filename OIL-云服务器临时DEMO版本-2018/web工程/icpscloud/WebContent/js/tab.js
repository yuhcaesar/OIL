/**
 * Dependence jquery-1.7.2.min.js
 **/
$(function(){
    function tabs(tabTit,on,tabCon,tabMore){
    $(tabCon).each(function(){
      $(this).children().eq(0).show().siblings().hide();
      });
    $(tabTit).each(function(){
      $(this).children().eq(0).addClass(on);
      });
    $(tabMore).each(function(){
      $(this).children().eq(0).show().siblings().hide();
      });
     $(tabTit).children().hover(function(){
        $(this).addClass(on).siblings().removeClass(on);
         var index = $(tabTit).children().index(this);
         $(tabCon).children().eq(index).show().siblings().hide();
         $(tabMore).children().eq(index).show().siblings().hide();
    });
     }
  tabs(".tab-hd","hover",".tab-bd",".tabmore");
   });
