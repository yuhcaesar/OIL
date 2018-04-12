<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
 <%@taglib prefix="s" uri="/struts-tags" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>物联网云-注册</title>

<link rel="stylesheet" type="text/css" href="${pageContext.request.contextPath}/css/Font.css"/>
<script>
	function checkForm(){
		// 校验用户名:
		// 获得用户名文本框的值:
		var username = document.getElementById("username").value;
		if(username == null || username == ''){
			alert("用户名不能为空!");
			return false;
		}
		// 校验密码:
		// 获得密码框的值:
		var password = document.getElementById("password").value;
		if(password == null || password == ''){
			alert("密码不能为空!");
			return false;
		}
		// 校验确认密码:
		var repassword = document.getElementById("repassword").value;
		if(repassword != password){
			alert("两次密码输入不一致!");
			return false;
		}
	}
	function checkUsername(){		
		// 获得文件框值:
		var username = document.getElementById("username").value;
		// 1.创建异步交互对象
		var xhr = createXmlHttp();
		// 2.设置监听
		xhr.onreadystatechange = function(){
			if(xhr.readyState == 4){
				if(xhr.status == 200){
					document.getElementById("span1").innerHTML = xhr.responseText;
				}
			}
		}
		// 3.打开连接
		xhr.open("GET","${pageContext.request.contextPath}/user_findByName.action?time="+new Date().getTime()+"&username="+username,true);

		var realname = document.getElementById("realname").value;
		if(realname == null || realname == ''){
			alert("用户名不能为空!");
			return false;
		}else if(!realname.matches("\\w{3,8}")){//用户名：必须输入，且3~8位的字母组成<br>
			alert("用户名必须输入，且3~8位的字母组成!");
		}
		// 校验密码:
		// 获得密码框的值:
		var password = document.getElementById("password").value;
		if(password == null || password == ''){
			alert("密码不能为空!");
			return false;
		}
		// 校验确认密码:
		var repassword = document.getElementById("repassword").value;
		if(repassword != password){
			alert("两次密码输入不一致!");
			return false;
		}
		
		//校验邮箱
		var email = document.getElementById("email").value;
		if(email == null || email == ''){
			alert("邮箱不能为空!");
			return false;
		}else if(!email.matches("\\b^['_a-z0-9-\\+]+(\\.['_a-z0-9-\\+]+)*@[a-z0-9-]+(\\.[a-z0-9-]+)*\\.([a-z]{2}|aero|arpa|asia|biz|com|coop|edu|gov|info|int|jobs|mil|mobi|museum|name|nato|net|org|pro|tel|travel|xxx)$\\b")){
			alert("邮箱格式不正确!");
			return false;
		}
	}
	function checkUsername(){		
		// 获得文件框值:
		var realname = document.getElementById("realname").value;
		// 1.创建异步交互对象
		var xhr = createXmlHttp();
		// 2.设置监听
		xhr.onreadystatechange = function(){
			if(xhr.readyState == 4){
				if(xhr.status == 200){
					document.getElementById("span1").innerHTML = xhr.responseText;
				}
			}
		}
		// 3.打开连接
		xhr.open("GET","${pageContext.request.contextPath}/user_findByName.action?time="+new Date().getTime()+"&realname="+realname,true);

		// 4.发送
		xhr.send(null);
	}
	
	function createXmlHttp(){
		   var xmlHttp;
		   try{ // Firefox, Opera 8.0+, Safari
		        xmlHttp=new XMLHttpRequest();
		    }
		    catch (e){
			   try{// Internet Explorer
			         xmlHttp=new ActiveXObject("Msxml2.XMLHTTP");
			      }
			    catch (e){
			      try{
			         xmlHttp=new ActiveXObject("Microsoft.XMLHTTP");
			      }
			      catch (e){}
			      }
		    }

			return xmlHttp;
		 }
	
	
	
</script>
</head>
<body>
 <!--整个页面-->
    <div id="page">
    
       <!-- 页面头 -->          
       <div id="div_top">
          <table align= "center" with=100%>            
            <tr>
             <td><font id="font_logo" ">物联网实验室云平台</font>
             </td>
           </tr>   
          </table>
          <table align= "center" with=100%> 
         <tr>
             <td><font id="font_logo">注册</font>
             </td>
           </tr>   
             
          
          </table>
       </div>
       
       <!-- 页面登录 -->
       <div id="div_login">
          <form name="form_regist" action="regist.action" onsubmit="return checkForm();">
             <table align= "center" with="100%">
                <tr>
                   <td>用户名
                   </td>
                   <td>
                      <input type="text" name="userName" onblur="checkUsername()"> 
                      <span id="span1"></span>                  
                   </td>                                
                </tr>
                <tr>
                   <td>密码
                   </td>
                   <td>
                      <input type="password" name="password" >                   
                   </td>                                
                </tr>
                 <tr>
                   <td>确认密码
                   </td>
                   <td>
                      <input type="password" name="repassword" >                   
                   </td>                                
                </tr>
                 <tr>
                   <td>姓名
                   </td>
                   <td>
                      <input type="text" name="realname" >                   
                   </td>                                
                </tr> 
                      <tr>
                   <td>性别
                   </td>
                   <td>
                      <input type="text" name="sex" >                   
                   </td>                                
                </tr> 
                <tr>
                   <td>公司
                   </td>
                   <td>
                      <input type="text" name="bussiness_id" >                   
                   </td>                                
                </tr>   
                <tr>
                   <td>邮箱
                   </td>
                   <td>
                      <input type="text" name="email" >                   
                   </td>                                
                </tr>
                <tr>
                   <td>手机号
                   </td>
                   <td>
                      <input type="text" name="phone" >                   

                      <input type="text" name="realname" onblur="checkUsername()"> 
                      
                      <span id="span1"></span>                  
                   </td>                                
                </tr>  
                 <tr>
                   <td>部门
                   </td>
                   <td>
                      <input type="text" name="department_id" >                   
                   </td>                                
                </tr> 
                <tr>
                   <td>邮箱
                   </td>
                   <td>
                      <input type="text" name="email" >       
                   </td>                                
                </tr>
                <tr>
                   <td>手机号
                   </td>
                   <td>
                      <input type="text" name="phone" >         
                   </td>                                
                </tr>
                <tr>
                   <td>区域
                   </td>
                   <td>
                      <input type="text" name="authority" > 
                      <td>
                         
                      </td>            
                   </td>                                
                </tr>
                 <tr>
                   <td>验证码
                   </td>
                   <td>
                      <input type="text" name="GraphicVerification" > 
                      <td>
                         
                      </td>            
                   </td>                                
                </tr>
          
                <tr>
                   <td>
                      <input type="submit" name="user_submit" value="普通用户注册"> 
                   </td>
                   <td>
                      <input type="submit" name="admin_submit" value="企业管理员注册">                   
                   </td>         
                   <td>
                      <input type="reset" name="reset" value="取消">                   
                   </td>                        
                </tr>
             
             </table>
       
          </form>
       </div>
              
       <!-- 页面底部 -->
       <div id="div_bottom">
       
       </div>	
    </div>




</body>
</html>