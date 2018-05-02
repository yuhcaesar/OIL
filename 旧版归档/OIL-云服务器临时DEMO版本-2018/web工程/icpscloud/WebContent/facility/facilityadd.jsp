<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>列表详细页 </title>
	<link rel="stylesheet" type="text/css" href="../css/style.css">
	<link rel="stylesheet" type="text/css" href="../css/base.css">
	<link rel="stylesheet" href="../css/register.css" />
</head>
<body>
	<div class="top">
		<div class="center">
			<span class="left">欢迎来到东北大学物联网云平台，请 <a href="#">登录</a> | <a href="#">注册</a></span>
			<span class="right"><a href="#">帮助我们</a> | <a href="#">关于我们</a></span>
		</div>
	</div>
	<div class="header">
		<div class="center">
			<span>东北大学物联网云平台</span>
			<img src="../images/by.png">
		</div>
	</div>
	<div class="nav">
		<div class="nav_bar">
            <ul class="nav clearfix">
            	<li class="m">
                    	<h3><a target="_blank" href="#" title="关于我们"><img class="a8" src="../../images/8.png">关于我们</a></h3>
                </li>
                <li class="m">
                    	<h3><a target="_blank" href="#" title="政策法规"><img class="a7" src="../images/7.png">政策法规</a></h3>
                </li>
                <li class="m">
                    	<h3><a target="_blank" href="#" title="技术需求"><img class="a6"  src="../images/6.png">技术需求</a></h3>
                </li>
                <li class="m">
                    <h3><a  target="_blank" href="#" title="科研基地"><img class="a5"src="../images/5.png">科研基地</a></h3>
                    <ul class="sub">
	                       <LI ><A href="#">科研基地</A> </LI>
	                       <LI ><A href="#">科研基地</A> </LI>
                    </ul>
                </li>

                <li class="m">
                    <h3><a target="_blank" href="#" title="科技专家库"><img class="a4"  src="../images/4.png">科技专家库</a></h3>
                    <ul class="sub">
	                      <LI ><A href="#">科技专家库</A>  </LI>
	                      <LI ><A href="#">科技专家库</A> </LI>
	                      <LI ><A href="#">科技专家库</A> </LI>
	                      <LI ><A href="#">科技专家库</A></LI> 
                    </ul>
                </li>
                <li class="m">
                    <h3><a target="_blank" href="#" title="成果专利库"><img  class="a3" src="../images/3.png">成果专利库</a></h3>
                    <ul class="sub">
	                     <LI ><A href="#">成果专利库</A> </LI>
	                     <LI ><A href="#">成果专利库</A> </LI>
					 </ul>
                </li>
                <li class="m">
                    <h3><a  target="_blank" href="list.html" title="资讯动态"><img class="a2" src="../images/2.png">资讯动态</a></h3>
                    <ul class="sub">
	                    <LI ><A href="#">资讯动态</A> </LI>
	                    <LI ><A href="#">资讯动态</A> </LI>
	                    <LI ><A href="#">资讯动态</A> </LI>
	                    <LI ><A href="#">资讯动态</A> </LI>
                    </ul>
                </li>
                <li class="m">
                    <h3><a  href="index.html" title="首页"><img class="a1" src="../images/1.png">首页</a></h3>
                </li>
                <li class="block"></li>
            </ul>
        </div>
	</div>
	
        <div id="content-l">
           <div class="list-content">       
                <div style =" border:1px solid black;height:900px;width:1200px;background-color:#ECF5FF;margin-top:20px;">        
	               <div id="main">
        	<h1>添加设备</h1>
        	<div style="height:15px"><div style="height:5px" id= "checkname"></div>
        	</div>
        	<form id="form" class="form" method="post" action="addFacility.action">
        		<!-- 管理员信息，同时是其他用户的基本信息 -->
        		<div id ="x0" style='display:block;overflow:hidden;text-align:center;'>
        		<div class="row userName">
        			<input type="text" id="devid" name="devid" placeholder="设备唯一标识" />
        		</div>
        		<div class="row pass">
        			<input type="text" id="devname" name="devname" placeholder="设备名字" />
        		</div>        		
        		<div class="row realName">
        			<input type="text" id="data_type_id" name="data_type_id" placeholder="采集信息格式id" />
        		</div>
        		<div class="row realName">
        			<input type="text" id="business_id" name="business_id" placeholder="备注面向的公司id" />
        		</div>
        		<div class="row realName">
        			<input type="text" id="department_id" name="department_id" placeholder="所属部门id" />
        		</div>
        		<div class="row birthday">
        			<input type="text" id="info" name="info" placeholder="设备采集到数据的单位" />
        		</div>
        		<div class="row email">
	    			<input type="text" id="maker" name="maker" placeholder="制造商" />
        		</div>
        		<div class="row telphone">
        			<input type="text" id="phone" name="phone" placeholder="联系方式" />
        		</div>
        		<div class="row telphone">
        			<input type="text" id="ctime" name="ctime" placeholder="安装时间" />
        		</div>       		
        		</div>     		              		       	    		     	
        		<input type="submit" value="添加" />     	
        	</form>
       </div>          
     </div>                              
    <div class="footer">
        <span>Copyright © 2017 东北大学物联网云平台</span>
        <span>技术支持：物联网实验室</span>
    </div>
    </div>
    <script type="text/javascript" src="js/jquery-1.8.0.min.js" /></script>
    <script type="text/javascript" src="js/js_jquery1.8.2.js" /></script>
    <script type="text/javascript" src="js/js_jquery.SuperSlide.2.1.1.js" /></script>
    <script type="text/javascript" src="js/nav.js"></script>
</body>
</html>