using ImpactaAPI.Context;
using ImpactaAPI.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace ImpactaAPI.Controllers;

[Route("api/[controller]")]
[ApiController]
public class HitsNumberController : ControllerBase
{
    //TODO 
    private readonly AppDbContext _context;

    public HitsNumberController(AppDbContext context)
    {
        _context = context;
    }

    [HttpGet("{id:int}", Name = "ObterHitNumber")]
    public ActionResult<HitsNumber> Get(int id)
    {
        var hitNumber = _context.HitsNumberDb.FirstOrDefault(p => p.id == id);
        if (hitNumber is null)
        {
            return NotFound("Jogada não encontrado");
        }
        return hitNumber;
    }

    [HttpPost]
    public ActionResult Post(HitsNumber hitsNumber)
    {
        if (hitsNumber is null)
            return BadRequest();

        _context.HitsNumberDb.Add(hitsNumber);
        _context.SaveChanges();

        return new CreatedAtRouteResult("ObterHitNumber",
            new { id = hitsNumber.id }, hitsNumber);
    }
}
