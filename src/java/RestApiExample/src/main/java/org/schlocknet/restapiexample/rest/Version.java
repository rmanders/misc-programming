package org.schocknet.restapiexample.rest;

import java.io.IOException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

/**
 *
 * @author Ryan Anderson 
 * 
 */

@Controller
@RequestMapping("/api")
public class Version {
  
    @RequestMapping(method = RequestMethod.GET, value = "/version", produces = "plain/text")
    @ResponseBody
    public String getVersion(HttpServletRequest request, HttpServletResponse response) 
	throws IOException {
	return "1.0.0";
    }  
}
