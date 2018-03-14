package com.icpscloud.util;

import java.io.IOException;
import java.io.PrintWriter;
import java.io.StringWriter;

import org.apache.log4j.Logger;


public class ExceptionUtil {

		private static final Logger logger = Logger.getLogger(ExceptionUtil.class);

		/**
		 * ·µ»Ø´íÎóÐÅÏ¢×Ö·û´®
		 * 
		 * @param ex
		 *            Exception
		 * @return ´íÎóÐÅÏ¢×Ö·û´®
		 */
		public static String getExceptionMessage(Exception ex) {
			StringWriter sw = new StringWriter();
			PrintWriter pw = new PrintWriter(sw);
			ex.printStackTrace(pw);
			String errorMessage = sw.toString();
			pw.close();
			try {
				sw.close();
			} catch (IOException e) {
				logger.error(e);
			}
			return errorMessage;
		}
	
	
}
