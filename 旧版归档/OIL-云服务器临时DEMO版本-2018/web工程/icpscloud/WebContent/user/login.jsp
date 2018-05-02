<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
 <%@taglib prefix="s" uri="/struts-tags" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>物联网云—登录</title>
<link rel="stylesheet" type="text/css" href="${pageContext.request.contextPath}/css/Font.css"/>

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
             <td><font id="font_logo">登录</font>
             </td>
           </tr>   
             
          
          </table>
       </div>
     
       
       <!-- 页面登录 -->
       <div id="div_login">
          <form name="form_login" action="login.action">
             <table align= "center" with="100%">
                <tr>
                   <td>
                   <font id="font_label">用户名：</font>
                   </td>
                   <td>
                      <input type="text" name="userName" >                   
                      <input type="text" name="realname" >                   

                   </td>                                
                </tr>
                <tr>
                   <td>密码：
                   </td>
                   <td>
                      <input type="password" name="password" >                   
                   </td>                                
                </tr>
                 <tr>
                   <td>验证码：
                   </td>
                   <td>
                      <input type="text" name="GraphicVerification" > 
                      <td>

                      </td>            
                   </td>                                
                </tr>
             
                <tr>
                   <td>
                      <input type="submit" name="user_submit" value="用户登录"> 
                   </td>
                   <td>
                      <input type="submit" name="admin_submit" value="管理员登录">                   
                   </td>         
                   <td>
                      <input type="reset" name="reset" value="取消">                   
                   </td>   
                 
                   <td>
                      <a href="error.jsp" >忘记密码</a>                  
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