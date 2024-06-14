using ImpactaAPI.Context;
using ImpactaAPI.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using System.Linq;

namespace ImpactaAPI.Controllers;

[Route("api/[controller]")]
[ApiController]
public class GamesNumberController : ControllerBase
{
    //TODO 
    private readonly AppDbContext _context;

    public GamesNumberController(AppDbContext context)
    {
        _context = context;
    }

    [HttpGet("{id:int}", Name = "ObterGameNumber")]
    public ActionResult<GamesNumber> Get(int id)
    {
        var gameNumber = _context.GamesNumberDb.FirstOrDefault(p => p.id == id);
        if (gameNumber is null)
        {
            return NotFound("Jogada não encontrado");
        }
        return gameNumber;
    }

    [HttpPost]
    public ActionResult Post(GamesNumber gamesNumber)
    {
        if (gamesNumber is null)
            return BadRequest();

        _context.GamesNumberDb.Add(gamesNumber);
        _context.SaveChanges();

        return new CreatedAtRouteResult("ObterGameNumber",
            new { id = gamesNumber.id }, gamesNumber);
    }

    [HttpDelete("DeleteLast")]
    public ActionResult DeleteLast()
    {
        // Ordena os registros em ordem decrescente pelo ID e pega o primeiro (último adicionado)
        var lastGameNumber = _context.GamesNumberDb
            .OrderByDescending(g => g.id)
            .FirstOrDefault();

        if (lastGameNumber == null)
            return NotFound("Nenhuma jogada encontrada");

        _context.GamesNumberDb.Remove(lastGameNumber);
        _context.SaveChanges();

        return NoContent();
    }
}
