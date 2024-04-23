using ImpactaAPI.Context;
using ImpactaAPI.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace ImpactaAPI.Controllers;

[Route("api/[controller]")]
[ApiController]
public class LoginDataController : Controller
{
    private readonly AppDbContext _context;
    public LoginDataController(AppDbContext context)
    {
        _context = context;
    }

    [HttpGet("{id:int}", Name = "ObterLoginData")]
    public ActionResult<LoginData> Get(int id)
    {
        var loginData = _context.LoginDataDb.FirstOrDefault(p => p.id == id);
        if (loginData is null)
        {
            return NotFound("Login não encontrado...");
        }
        return loginData;
    }

    [HttpPost]
    public ActionResult Post(LoginData loginData)
    {
        if (loginData is null)
            return BadRequest();

        _context.LoginDataDb.Add(loginData);
        _context.SaveChanges();

        return new CreatedAtRouteResult("ObterLoginData",
            new { id = loginData.id }, loginData);
    }
}

