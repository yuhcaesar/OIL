<%@page import="org.springframework.context.ApplicationContext"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ page import="java.util.*"%>
<%@ page import="java.lang.System.*" %>
<%@ page import="business.icpscloud.user.entity.UserEntity"%>
<%@ page import="business.icpscloud.user.service.UserService"%>
<%@ page import="business.icpscloud.user.service.impl.UserServiceImpl"%>
<%@ page import="business.icpscloud.user.service.impl.UserServiceImpl"%>
<%@ page
	import="org.springframework.web.context.support.WebApplicationContextUtils"%>
<%
	ApplicationContext ac = WebApplicationContextUtils.getWebApplicationContext(this.getServletContext());
	UserService userService = (UserService) ac.getBean("userService");
	List<UserEntity> userList = userService.userReview();
%>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>title</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<script language="javascript" src="../script/jquery.js"></script>
<link type="text/css" rel="stylesheet"
	href="../style/css/pageCommon.css" />
<style>
#sub { /*按钮样式*/
	width: 90% px;
	height: 40px;
	line-height: 40px;
	background: transparent url(../style/images/button.png) no-repeat;
	border: none;
	font-size: 20px;
	cursor: pointer;
}

.but_div { /*按钮所在div*/
	align: center;
	text-align: center;
	margin: 0 auto;
	width: 90%;
	height: 40px;
	line-height: 40px;
}

.selectDiv { /*选择区所在div*/
	align: center;
	text-align: center;
	margin: 0 auto;
	width: 90%;
	height: 40px;
	line-height: 40px;
}

.contentDiv { /*各个板块样式*/
	align: center;
	text-align: center;
	margin: 0 auto;
	width: 90%;
	height: auto;
	line-height: auto;
	background-color: #bdddf2;
}
</style>

</head>
<body>
	<div id="Title_bar">
		<div id="Title_bar_Head">
			<div id="Title_Head"></div>
			<div id="Title">
				<!--页面标题-->
				<img border="0" width="13" height="13"
					src="../style/images/title_arrow.gif" /> 人员管理
			</div>
			<div id="Title_End"></div>
		</div>
	</div>
	<!-- <form id="form" name="form" method="post" action="relaseInfoAction.action"> -->

			<div>
				<table>
					<tr>
						<th>员工号</th>
						<th>所属部门</th>
						<th>电话</th>
						<th>邮箱</th>
						<th>authority</th>
						<th>审    核   </th>
					</tr>
					<c:forEach var="ccc" items="<%=userList%>">
						<tr>
							<td id =  "zhi" bgcolor="	#FFFFE0">${ccc.user_id}</td>
							<td id =  "zhi1">${ccc.business_id}</td>
							<td>${ccc.department_id}</td>
							<td>${ccc.department_id}</td>
							<td><a id="update" href="javascript:void(0)"  value="click"  onclick="clickf(${ccc.user_id})">审核pass</a> </td>
						</tr>
						<input type="button" onClick="check()" value="审核通过">
					</c:forEach>
				</table>
			</div>
			<div>
			<input id="zhi" value="hi" onClick=check(ccc.user_id)>
			</div>


	<script language="JavaScript" type="text/javascript">

		function clickf(id){
			$.ajax({
	            type: 'POST',
	            url: 'userconfirm',
	            data: {
	                user_id: id,
	            },
	            dataType: "json",
	            success:function(){
	            	alert("success")
	            }
	        });
			
			
			if(confirm("确认通过用户 "+ id+" 的申请吗？")){
				alert("success");
				//alert(id);
			}
			else{
				alert("fail");
			}
		} ;
		
		
	</script>
	<script type="text/javascript">
	
	
	</script>
	



</body>
</html>